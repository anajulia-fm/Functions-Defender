
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

// Função que define o inimigo
void makeEnemy(enemy_t e[ENEMYMAX]);


int main(){
    // Variaveis da função:
    enemy_t e[ENEMYMAX];

    //Variaveis de visualização:
    int timeFlag=1;
    long double start, end;
    
    makeEnemy(e);
    srand(time(NULL));
    while (1){
        if(timeFlag){
            start=(double)clock()/CLOCKS_PER_SEC;
            timeFlag=0;
        }
        end=(double)clock()/CLOCKS_PER_SEC;
        if(end-start>=2){
            timeFlag=1;
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
        
    }
    

    return 0;
}

// Cria inimigos:
void makeEnemy(enemy_t e[ENEMYMAX]){
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


