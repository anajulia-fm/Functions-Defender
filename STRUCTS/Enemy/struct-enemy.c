
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<conio2.h>
#include<time.h>

#define ENEMYMAX 20

#define ENEMYMOVMX 3
#define ENEMYMOVMN 1

// Enemy:
typedef struct{
    int active;
    int lifes;
    int xAsis, yAsis;
    int print;
    int move, moveFlag, needToMove;
    /*
        Onde:
          - int active -> Indica se o inimigo está ativo
          - int xAsis -> Posção no eixo X
          - int yAsis -> Posição no eixo Y
          - int lifes -> Numero de vidas do inimigo
          - int move -> Indica qual sera a movimentação do inimigo
          - int print -> Indica se deve ser impresso;
          - int moveFlag -> Indica a quanto tempo o inimigo se encontra em uma movimentação x
    */
}enemy_t;

// Só visualização:
//=========================================================
    #define MXPTR 105 // Limite de impressão
    #define MXJU 500 // Valor maximo do J da matrizUniverso
    #define MXIU 35 //  Valor maximo do I da matrizUniverso
    #define MXJBIN 76

    typedef struct{
        int initalX, finalX;
        int u[MXIU][MXJU];
    }map_t;

    // Imprime o map
    int printMap(map_t m);
    // Preenche o mapa lido com 'C's
    void fillGaps(char mapaDoArquivoBinario[][MXJBIN]);
//=========================================================

// Função que cria um Array de inimigos Default:
void makeEnemyArray(enemy_t e[ENEMYMAX]);
// Função que cria um inimigo:
void makeEnemy(int i, int j, enemy_t e[ENEMYMAX], int *enemyNumber);
// Fução que move os inimigos:
void moveEnemy(enemy_t e[ENEMYMAX], map_t m);

// MODIFICADA:
// Tranfere o conteudo do mapa lido para o mapa do jogo
void makeMap(char bin[][MXJBIN], map_t *m, enemy_t e[ENEMYMAX], int *enemyNumber);


int main(){
    // Variaveis da função:
    enemy_t e[ENEMYMAX];
    int enemyNumber;

    //Variaveis de visualização:
    map_t map;
    int timeFlag=1;
    int i, j;
    int x=0, endgame=0, aux=0;
    char c;
    long double start, end;
    char bin[MXIU][MXJBIN]={"CC                                                             CCCCCCCCCCCC", " CC                CCCCC                                     CCC           ", "  CCCCCC          CC   CC                               CCCCCC             ", "       CCCC     CCC     CC               CCCC         CCC                  ", "          CCCCCCC        C             CCC  CC      CCC                    ", "                         CCCCCCCCC    CC     CCCCCCCC                      ", "                                 CCCCCC                                    ", "                                                                           ", "                                                                           ", "                            X                                              ", "                                                                           ", "                                     X                                     ", "                                                                           ", "                                                                           ", "                                                                           ", "                                                                           ", "                                                                           ", "                                                                           ", "                                                                           ", "                                                                           ", "                                                                           ", "                                                                           ", "                                                                           ", "                                                                           ", "                                                                           ", "                                                                           ", "                                                                          X", "                                                                           ", "      X                                                                    ", "           CCCCCCC                                                         ", "   CCCCCCCCC     C                                   C                     ", "CCCC             CC                                CC C                  CC", "                  CCC                             CC  CC                CC ", "                    CC                           CC    CCCCCCCCCCCCCCCCCC  ", "                     CCCCCCCCCCCCCCCCCCCCCCCCCCCCC                         "};
    // Cria Array de Inimigos:
    makeEnemyArray(e);

    fillGaps(bin);
    enemyNumber=0;
    makeMap(bin, &map, e, &enemyNumber);
    printMap(map);
    while(1){
        // Inicia timer
        if(timeFlag){
            start=(double)clock()/CLOCKS_PER_SEC;
            timeFlag=0;
        }
        if(kbhit()){
            c=getch();
        }
        if(c=='d'){
            map.finalX++;
            map.initalX++;
            c='z';
        }
        end=(double)clock()/CLOCKS_PER_SEC;
        if(map.initalX!=aux){
            endgame=printMap(map);
            aux=map.initalX;
            moveEnemy(e, map);
            printEnemy(e, map);
            timeFlag=1;
        }else if(end-start>=.25){
            timeFlag=1;
            moveEnemy(e, map);
            printEnemy(e, map);
        }
    }

    return 0;
}

// Cria Array de inimigos:
void makeEnemyArray(enemy_t e[ENEMYMAX]){
    int i;

    for(i=0;i<ENEMYMAX;i++){
        e[i].active=0;
        e[i].lifes=1;
        e[i].xAsis=0;
        e[i].yAsis=0;
        e[i].move=0;
        e[i].print=0;
        e[i].moveFlag=0;
        e[i].needToMove=1;
    }
}
// Cria um inimigo
void makeEnemy(int i, int j, enemy_t e[ENEMYMAX], int *enemyNumber){
    int k, flag;

    gotoxy(1, 40);
    printf("%d", *enemyNumber);
    if(*enemyNumber<ENEMYMAX){
        flag=0;
        k=0;
        do{
            if(!e[k].active){
                e[k].active=1;
                e[k].xAsis=j;
                e[k].yAsis=i;
                flag=1;
                (*enemyNumber)++;
            }else{
                k++;
            }
        }while(!flag);
    }
}
// Movimenta os inimigos
void moveEnemy(enemy_t e[ENEMYMAX], map_t m){
    int i;

    srand(time(NULL));
    for(i=0;i<ENEMYMAX;i++){
        if(e[i].xAsis<=m.initalX){
            e[i].needToMove=0;
        }
        // Move se estiver ativo
        if(e[i].active){
            if(e[i].needToMove){
                if(e[i].moveFlag==0){
                    e[i].move=0;
                }
                // Coloca uma posição
                if(e[i].move==0){
                    e[i].move=ENEMYMOVMN+(rand()%(ENEMYMOVMX-ENEMYMOVMN+1));
                    e[i].moveFlag=4;
                }
                // Limpa posição anterir
                if(e[i].print){
                    gotoxy(e[i].xAsis-m.initalX, e[i].yAsis+2);
                    printf("  ");
                    gotoxy(e[i].xAsis-m.initalX, e[i].yAsis+1);
                    printf("  ");
                }
                // Move eixo X
                if(m.u[e[i].yAsis][e[i].xAsis-1]=='C'||m.u[e[i].yAsis][e[i].xAsis-2]=='C'||m.u[e[i].yAsis][e[i].xAsis-3]=='C'||m.u[e[i].yAsis][e[i].xAsis-4]=='C'||m.u[e[i].yAsis][e[i].xAsis-5]=='C'||m.u[e[i].yAsis-1][e[i].xAsis-1]=='C'||m.u[e[i].yAsis-1][e[i].xAsis-2]=='C'||m.u[e[i].yAsis-1][e[i].xAsis-3]=='C'||m.u[e[i].yAsis-1][e[i].xAsis-4]=='C'||m.u[e[i].yAsis-1][e[i].xAsis-5]=='C'){
                    if(e[i].yAsis<=17){
                        e[i].yAsis++;
                    }else if(e[i].yAsis>=18){
                        e[i].yAsis--;
                    }
                    e[i].moveFlag=0;
                }
                if(m.u[e[i].yAsis][e[i].xAsis-1]!='C'&&m.u[e[i].yAsis][e[i].xAsis-2]!='C'&&m.u[e[i].yAsis][e[i].xAsis-3]!='C'&&m.u[e[i].yAsis][e[i].xAsis-4]!='C'&&m.u[e[i].yAsis][e[i].xAsis-5]!='C'&&m.u[e[i].yAsis-1][e[i].xAsis-1]!='C'&&m.u[e[i].yAsis-1][e[i].xAsis-2]!='C'&&m.u[e[i].yAsis-1][e[i].xAsis-3]!='C'&&m.u[e[i].yAsis-1][e[i].xAsis-4]!='C'&&m.u[e[i].yAsis-1][e[i].xAsis-5]!='C'){
                    e[i].xAsis--;
                    // Move eixo Y
                    switch (e[i].move){
                        // Para cima
                        case 1:
                            if(m.u[e[i].yAsis-2][e[i].xAsis]=='C'||m.u[e[i].yAsis-3][e[i].xAsis]=='C'||m.u[e[i].yAsis-4][e[i].xAsis]=='C'||m.u[e[i].yAsis-5][e[i].xAsis]=='C'||m.u[e[i].yAsis-6][e[i].xAsis]=='C'||m.u[e[i].yAsis-2][e[i].xAsis+1]=='C'||m.u[e[i].yAsis-3][e[i].xAsis+1]=='C'||m.u[e[i].yAsis-4][e[i].xAsis+1]=='C'||m.u[e[i].yAsis-5][e[i].xAsis+1]=='C'||m.u[e[i].yAsis-6][e[i].xAsis+1]=='C'){
                                e[i].yAsis++;
                                e[i].moveFlag=0;
                            }else{
                                e[i].yAsis--;
                            }
                            break;
                        // Linha reta
                        case 2:
                            if(m.u[e[i].yAsis-2][e[i].xAsis]=='C'||m.u[e[i].yAsis-2][e[i].xAsis+1]=='C'||m.u[e[i].yAsis-3][e[i].xAsis]=='C'||m.u[e[i].yAsis-3][e[i].xAsis+1]=='C'){
                                if(e[i].xAsis<=17){
                                    e[i].yAsis++;
                                }else if(e[i].xAsis>=18){
                                        e[i].yAsis--;
                                }
                            }
                            break;
                        // Para baixo
                        case 3:
                            if(m.u[e[i].yAsis+1][e[i].xAsis]=='C'||m.u[e[i].yAsis+2][e[i].xAsis]=='C'||m.u[e[i].yAsis+3][e[i].xAsis]=='C'||m.u[e[i].yAsis+1][e[i].xAsis+1]=='C'||m.u[e[i].yAsis+2][e[i].xAsis+1]=='C'||m.u[e[i].yAsis+3][e[i].xAsis+1]=='C'){
                                e[i].yAsis--;
                                e[i].moveFlag=0;
                            }else{
                                e[i].yAsis++;
                            }
                            break;
                    }
                    // if(m.u[e[i].yAsis][e[i].xAsis]=='C'||m.u[e[i].yAsis-1][e[i].xAsis]=='C'||m.u[e[i].yAsis][e[i].xAsis+1]=='C'||m.u[e[i].yAsis-1][e[i].xAsis+1]=='C'){
                    //     if(e[i].yAsis<=17){
                    //     e[i].yAsis++;
                    //     }else if(e[i].yAsis>=18){
                    //         e[i].yAsis--;
                    //     }
                    //     e[i].move=0;
                    // }
                    e[i].moveFlag--;
                    if(e[i].moveFlag<0){
                        e[i].moveFlag=0;
                    }

                }
            }
        }
    }
}
// Vê se inimigo pode ser impresso:
void printEnemy(enemy_t e[ENEMYMAX], map_t m){
    int i;
    static int j;

    for(i=0; i<ENEMYMAX; i++){
        if(e[i].xAsis>m.initalX&&e[i].xAsis<m.finalX&&e[i].active){
            e[i].print=1;
            gotoxy(e[i].xAsis-m.initalX, e[i].yAsis+2);
            printf("#%d", e[i].moveFlag);
            gotoxy(e[i].xAsis-m.initalX, e[i].yAsis+1);
            printf("#%d", e[i].move);
        }else{
            e[i].print=0;
        }
    }
}


// MODIFICADAS: CYCLE-MAP/print.c -> this

// Copia a matriz mapaDoArquivoBinario quantas vezes for necessario
// até preencher a matrizUniverso - mapa do jogo
void makeMap(char bin[][MXJBIN], map_t *m, enemy_t e[ENEMYMAX], int *enemyNumber){
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
                makeEnemy(i, j, e, enemyNumber);
            }
        }
    }
    m->initalX=1;
    m->finalX=MXPTR;
}


// VISUALIZAÇÃO
// Imprime o mapa
int printMap(map_t m){
    int i, j, flag;

    flag=0;
    gotoxy(1, 2);
    if(m.initalX!=415){
        for(i=0; i<MXIU; i++){
            for(j=m.initalX; j<MXPTR+m.initalX; j++){
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
