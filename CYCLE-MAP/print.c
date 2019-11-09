#include<stdio.h>
#include<stdlib.h>
#include<conio2.h>
#include<conio.h>

#define MXPTR 105   // Limite de impressão
#define MXJU 500 // Valor maximo do J da matrizUniverso
#define MXIU 35  //  Valor maximo do I da matrizUniverso
#define MXJBIN 76

int ptr_map(int matrizUniverso[][MXJU], int x);

int main(){
    // Variaveis de visualizacao:
    int x=0, endgame=0, aux=0;
    char c;

    // Variaveis da function:
    int matrizUniverso[MXIU][MXJU]; // Matriz universo
    char mapaDoArquivoBinario[MXIU][MXJBIN]={"CC                                                             CCCCCCCCCCCC", " CC                CCCCC                                     CCC           ", "  CCCCCC          CC   CC                               CCCCCC             ", "       CCCC     CCC     CC               CCCC         CCC                  ", "          CCCCCCC        C             CCC  CC      CCC                    ", "                         CCCCCCCCC    CC     CCCCCCCC                      ", "                                 CCCCCC                                    ", "                                                                           ", "                                                                           ", "                                                                           ", "                                                                           ", "                                                                           ", "                                                                           ", "                                                                           ", "                                                                           ", "                                                                           ", "                                                                           ", "                                                                           ", "                                                                           ", "                                                                           ", "                                                                           ", "                                                                           ", "                                                                           ", "                                                                           ", "                                                                           ", "                                                                           ", "                                                                           ", "                                                                           ", "                                                                           ", "           CCCCCCC                                                         ", "   CCCCCCCCC     C                                   C                     ", "CCCC             CC                                CC C                  CC", "                  CCC                             CC  CC                CC ", "                    CC                           CC    CCCCCCCCCCCCCCCCCC  ", "                     CCCCCCCCCCCCCCCCCCCCCCCCCCCCC                         "};

    // Rotina FillGaps: Aloca uns nos 'buracos'
    {
        // FLAGS:
        int flag=0, iFlag=0;
        // AUX:
        int auxI=0, i=0, j=0;

        j=0;
        do{
            flag=0;
            i=0;
            do{
                iFlag=0;
                if(mapaDoArquivoBinario[i][j]=='C'){
                    //Parte Superior do Mapa
                    if(i<=17){
                        auxI=i-1;
                        if(auxI<0){
                            auxI=0;
                        }else{
                            auxI=1;
                        }
                        // Preenche
                        if(auxI){
                            if(mapaDoArquivoBinario[i-1][j]==' '){
                                for(auxI=i-1;auxI>=0;auxI--){
                                    mapaDoArquivoBinario[auxI][j]='C';
                                }
                            }
                        }

                    }
                    //Parte Inferior do Mapa
                    if(i>=18){
                        // Testa se não acessa areas de memoria indesejadas
                        auxI=i+1;
                        if(auxI>MXIU){
                            auxI=0;
                        }else{
                            auxI=1;
                        }
                        if(auxI){
                            if(mapaDoArquivoBinario[i+1][j]==' '){
                                for(auxI=i+1;auxI<MXIU;auxI++){
                                    mapaDoArquivoBinario[auxI][j]='C';
                                }
                                iFlag=1;
                            }
                        }
                    }
                }
                i++;
            }while(i<MXIU&&!iFlag);
            j++;
        }while(j!=MXJBIN-1);
    }
    // Function de Loop:
    {
        int i, j; // (x, y) da matriz Universo
        int k, l; // (x, y) da matriz lida do arquivo
        int horaDoLoop=0;

        for(j=0, l=0; j<MXJU;j++, l++){
            if(horaDoLoop){
                l=0;
            }
            horaDoLoop=0;
            for(i=0, k=0;i<MXIU;i++, k++){
                if(l==MXJBIN-2){
                    horaDoLoop=1;
                }
                matrizUniverso[i][j]=0+mapaDoArquivoBinario[k][l];
            }
        }
    }
    // So para visualização!
    ptr_map(matrizUniverso, x);
    while(!endgame){
        c=getch();
        if(c=='d'){
            x++;
            c='z';
        }
        if(x!=aux){
            endgame=ptr_map(matrizUniverso, x);
            aux=x;
        }
    }

return 0;
}

int ptr_map(int matrizUniverso[][MXJU], int x){
    int i, j, flag;

    flag=0;
    gotoxy(1, 2);
    if(x!=415){
        for(i=0; i<MXIU; i++){
            for(j=0+x; j<MXPTR+x; j++){
                if(matrizUniverso[i][j]=='C'){
                    textcolor(WHITE);
                    printf("%c", 219);
                }else{
                    printf("x");
                }
            }
            printf("\n");
        }
    }else{
        flag=1;
    }

    return flag;
}
