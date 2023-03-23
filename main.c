   #include<stdlib.h>
   #include<stdio.h>



int longueur(char chaine[100]){
    int nc = 0;
    for( nc = 0 ; chaine[nc] != '\0' ; nc++ ){}
    nc --;
    return nc;
}

int verification(char nombreentrer[100], int base ){
    int  i , j , veri = 1;
    char tab[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E',
    'F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    for (i = longueur(nombreentrer) ; i >= 0  && veri == 1 ; i--) {
        veri = 0;
        for (j = 0 ; j != base && veri == 0 ; j++){
            if ( nombreentrer[i] == tab[j] ){
                veri = 1;
            }
        }
    }
    return veri;
}

int baseversdecimale( char nombreentrer[100] , int base ){
    int basepower = 1 , reste = 0 , i , dec = 0;
    for(i = longueur(nombreentrer) ; i >= 0 ; --i){
        if(nombreentrer[i]>='0' && nombreentrer[i]<='9'){
            reste = nombreentrer[i] - '0';
        }
        else{
            reste = nombreentrer[i] - 'A' + 10;
        }
        dec = dec + reste * basepower ;
        basepower = basepower * base;
    }
    return dec;
}

void decimaleversbase(int dec , int base){
    int i, j = 0 , reste ;
    char hex[100];
    if (dec == 0)
        printf("0\n");
    else{
        while (dec != 0){
            reste = dec % base ;
            if (reste < 10){
                hex[j] = '0' + reste;
            }
            else{
                hex[j] = 'A' + reste - 10 ;
            }
            j++;
            dec = dec / base;
        }
        for(i = j - 1 ; i >= 0; i--)
            printf("%c", hex[i]);
        printf("\n");
    }
}
int main (){
    int  base1 , base2 ;
    char chaine[100];
    int ver;
    do{
    printf("CONVERTISSEURE DE BASE:\n");
    do {
        printf("entrer le nombre qui vous souhaitez convertir :\n");
        scanf("%s",chaine);
        printf("entrer la base :\n");
        scanf("%d",&base1);
        while (base1<=1||base1>=37){
            printf("la base est entre 2 et 36:\nentrer la base :\n");
            scanf("%d",&base1);
        }
        if (verification(chaine, base1) == 0)
            printf("erreur!!\n");
    }   while(verification(chaine, base1)== 0);
    do {
        printf("entrer la base vers laquel vous souhaitez convertir :\n");
        scanf("%d",&base2);
    }   while (base2<=1||base2>=37 );
    if (base2 == base1){
        printf("Dans la meme base le nombre est le meme!!\n%s --> %s\n", chaine,chaine);
    }
    else if (base1 == 10){
        printf("Decimale --> base %d.\n%s --> ",base2,chaine);
        decimaleversbase(baseversdecimale(chaine, 10), base2);
    }
    else if (base2 == 10){
        printf("Base %d --> decimale.\n%s --> %d\n",base1,chaine,baseversdecimale(chaine, base1));
    }
    else{
        printf("Base %d --> base %d.\n%s --> ",base1,base2,chaine);
        decimaleversbase(baseversdecimale(chaine, base1), base2);
    }
    printf("voulez vous convertir un autre nombre : \n Oui tappez 1 \n Non tappez 0 :\n");
    scanf("%d",&ver);
    }while( ver == 1);
    return 0;
    }
