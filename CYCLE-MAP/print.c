#include<stdio.h>
#include<stdlib.h>
#include<conio2.h>
#include<conio.h>

#define MXPTR 105   // Limite de impressão
#define MXJU 500 // Valor maximo do J da matrizUniverso
#define MXIU 35  //  Valor maximo do I da matrizUniverso
#define MXJBIN 76

typedef struct{
    int initalX, finalX;
    int u[MXIU][MXJU];
}map_t;

// Imprime o map
int printMap(map_t m);
// Preenche o mapa lido com 'C's
void fillGaps(char mapaDoArquivoBinario[][MXJBIN]);
// Tranfere o conteudo do mapa lido para o mapa do jogo
void makeMap(char bin[][MXJBIN], map_t *m);

int main(){
    // Variaveis de visualizacao:
    int x=0, endgame=0, aux=0;
    char c;
    // Variaveis da função:
    map_t map;
    //int matrizUniverso[MXIU][MXJU]; // Matriz universo
    char mapaDoArquivoBinario[MXIU][MXJBIN]={"CC                                                             CCCCCCCCCCCC", " CC                CCCCC                                     CCC           ", "  CCCCCC          CC   CC                               CCCCCC             ", "       CCCC     CCC     CC               CCCC         CCC                  ", "          CCCCCCC        C             CCC  CC      CCC                    ", "                         CCCCCCCCC    CC     CCCCCCCC                      ", "                                 CCCCCC                                    ", "                                                                           ", "                                                                           ", "                                                                           ", "                                                                           ", "                                                                           ", "                                                                           ", "                                                                           ", "                                                                           ", "                                                                           ", "                                                                           ", "                                                                           ", "                                                                           ", "                                                                           ", "                                                                           ", "                                                                           ", "                                                                           ", "                                                                           ", "                                                                           ", "                                                                           ", "                                                                           ", "                                                                           ", "                                                                           ", "           CCCCCCC                                                         ", "   CCCCCCCCC     C                                   C                     ", "CCCC             CC                                CC C                  CC", "                  CCC                             CC  CC                CC ", "                    CC                           CC    CCCCCCCCCCCCCCCCCC  ", "                     CCCCCCCCCCCCCCCCCCCCCCCCCCCCC                         "};

    // Rotina FillGaps: Aloca uns nos 'buracos'
    fillGaps(mapaDoArquivoBinario);
    // Function de Loop:
    makeMap(mapaDoArquivoBinario, &map);
    // So para visualização!
    printMap(map);
    while(!endgame){
        c=getch();
        if(c=='d'){
            map.finalX++;
            map.initalX++;
            x=map.initalX;
            c='z';
        }
        if(x!=aux){
            endgame=printMap(map);
            aux=x;
        }
    }

return 0;
}

// Imprime o mapa
int printMap(map_t m){
    int i, j, flag;

    flag=0;
    gotoxy(1, 2);
    if(m.initalX!=415){
        for(i=0; i<MXIU; i++){
            for(j=0+m.initalX; j<MXPTR+m.initalX; j++){
                if(m.u[i][j]=='C'){
                    textcolor(WHITE);
                    printf("%c", 219);
                }else{
                    printf(" ");
                }
            }
            printf("\n");
        }
    }else{
        flag=1;
    }

    return flag;
}
// Preenche os espaços com uns:
void fillGaps(char bin[][MXJBIN]){
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
            if(bin[i][j]=='C'){
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
                        if(bin[i-1][j]==' '){
                            for(auxI=i-1;auxI>=0;auxI--){
                                bin[auxI][j]='C';
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
                        if(bin[i+1][j]==' '){
                            for(auxI=i+1;auxI<MXIU;auxI++){
                                bin[auxI][j]='C';
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
// Copia a matriz mapaDoArquivoBinario quantas vezes for necessario
// até preencher a matrizUniverso - mapa do jogo
void makeMap(char bin[][MXJBIN], map_t *m){
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
            m->u[i][j]=0+bin[k][l];
            if(bin[k][l]=='@'){
                //atribui valor ao x Fixo do player
                bin[k][l]=' ';
            }else if(bin[k][l]=='X'){
                //Chama função que cria inimigos
            }
        }
    }
    m->initalX=1;
    m->finalX=MXPTR;
}
