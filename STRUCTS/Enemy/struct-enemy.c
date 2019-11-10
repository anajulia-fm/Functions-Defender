
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
    int printFlag;
    int move, moveFlag;
    char ship[2][3];
    /*
        Onde:
          - int active -> Indica se o inimigo está ativo
          - int xAsis -> Posção no eixo X
          - int yAsis -> Posição no eixo Y
          - int lifes -> Numero de vidas do inimigo
          - int printFlag -> Indica se esta na "Zona de impressão"
          - int move -> Indica qual sera a movimentação do inimigo
          - int moveFlag -> Indica a quanto tempo o inimigo se encontra em uma movimentação x
          - char ship -> Representação do inimigo;
    */
}enemy_t;

// Função que cria um Array de inimigos Default:
void makeEnemyArray(enemy_t e[ENEMYMAX]);
// Função que cria um inimigo:
void makeEnemy(int i, int j, enemy_t e[ENEMYMAX]);
// Fução que move os inimigos:
void moveEnemy(enemy_t e[ENEMYMAX]);

//=========================================================
// Só visualização:
int ptr_map(int matrizUniverso[][MXJU], int x);
void fillGaps(char mapaDoArquivoBinario[][MXJBIN]);

#define MXPTR 105   // Limite de impressão
#define MXJU 500 // Valor maximo do J da matrizUniverso
#define MXIU 15  //  Valor maximo do I da matrizUniverso
#define MXJBIN 16
//=========================================================

int main(){
    // Variaveis da função:
    enemy_t e[ENEMYMAX];

    //Variaveis de visualização:
    int timeFlag=1;
    int i, j;
    int x=0, endgame=0, aux=0;
    char c;
    long double start, end;
    char bin[15][16]={"CCCCCCCCCCCCCCC", "CCCCCC         ", " CCCC          ", "  CC           ", "               ", "               ", "               ", "               ", "               ", "               ", "              X", "               ", "CCC  C        C", "CCCCCCCC  CCCCC", "CCCCCCCCCCCCCCC"};
    int matU[MXIU][MXJU];

    makeEnemyArray(e);
    for(i=0;i<MXIU;i++){
        for(j=0;j<MXJU;j++){
            if(matU[i][j]=='X'){
                makeEnemy(i, j, e);
            }else if(matU[i][j]=='C'){
                printf("%c", 219);
            }else{
                printf(" ");
            }
        }
    }
    srand(time(NULL));
    while (1){
        if(timeFlag){
            start=(double)clock()/CLOCKS_PER_SEC;
            timeFlag=0;
        }
        end=(double)clock()/CLOCKS_PER_SEC;
        if(end-start>=2){
            timeFlag=1;
            moveEnemy(e);
        }
        
    }
    

    return 0;
}

// Cria inimigos:
void makeEnemyArray(enemy_t e[ENEMYMAX]){
    int i;

    for(i=0;i<ENEMYMAX;i++){
        e[i].active=0;
        e[i].lifes=1;
        e[i].printFlag=0;
        e[i].xAsis=0;
        e[i].yAsis=0;
        e[i].move=0;
        e[i].moveFlag=0;
        strncpy(e[i].ship[0], "##", 3);
        strncpy(e[i].ship[1], "##", 3);
    }
}

void makeEnemy(int i, int j, enemy_t e[ENEMYMAX]){
    static int enemyNumber=0;
    int k, flag;

    if(enemyNumber<ENEMYMAX){
        flag=0;
        k=0;
        do{
            if(!e[k].active){
                e[k].active=1;
                e[k].xAsis=j;
                e[k].yAsis=i;
                flag=1;
                enemyNumber++;
            }else{
                k++;
            }
        }while(!flag&);
    }
}

void moveEnemy(enemy_t e[ENEMYMAX]){
    int i;

    for(i=0;i<ENEMYMAX;i++){
        // Move se estiver ativo
        if(e[i].active){
            // Coloca uma posição
            if(e[i].move==0){
                e[i].move=ENEMYMOVMN+(rand()%(ENEMYMOVMX-ENEMYMOVMN+1));
                e[i].moveFlag=4;
            }
            // Move eixo X
            if(mapU[e[i].yAsis][e[i].xAsis-1]=='C'||mapU[e[i].yAsis][e[i].xAsis-2]=='C'||mapU[e[i].yAsis][e[i].xAsis-3]=='C'||mapU[e[i].yAsis][e[i].xAsis-4]=='C'){
                if(e[i].xAsis<=17){
                    e[i].yAsis++;
                }else{
                    e[i].yAsis--;
               } 
            }else{
                e[i].xAsis--;
                if(e[i].xAsis<0){
                    e[i].xAsis==0;
                }
            }
            // Move eixo Y
            switch (e[i].move){
                // Para cima
                case 1:
                    if(mapU[e[i].yAsis-1][e[i].xAsis]=='C'||mapU[e[i].yAsis-2][e[i].xAsis]=='C'||mapU[e[i].yAsis-3][e[i].xAsis]=='C'){
                        e[i].yAsis++;
                        e[i].moveFlag=0;
                    }else{
                        e[i].yAsis--;
                    }        
                    break;
                // Linha reta
                case 2:
                    break;
                // Para baixo
                case 3:
                    if(mapU[e[i].yAsis+1][e[i].xAsis]=='C'||mapU[e[i].yAsis+2][e[i].xAsis]=='C'||mapU[e[i].yAsis+3][e[i].xAsis]=='C'){
                        e[i].yAsis--;
                        e[i].moveFlag=0;
                    }else{
                        e[i].yAsis++;
                    }
                    break;            
            }
            e[i].moveFlag--;
            if(e[i].moveFlag<0){
                e[i].moveFlag=0;
            }
        }
    }
}