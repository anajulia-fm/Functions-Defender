
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<conio2.h>

#define ENEMYMAX 20

// Enemy:
typedef struct{
    int active, xAsis, yAsis, lifes, printFlag, move;
    char ship[2][3];
    /*
        Onde:
          - int active -> Indica se o inimigo está ativo
          - int xAsis -> Posção no eixo X
          - int yAsis -> Posição no eixo Y
          - int lifes -> Numero de vidas do inimigo
          - int printFlag -> Indica se esta na "Zona de impressão"
          - char ship -> Representação do inimigo;
    */
}enemy_t;

// Função que define o inimigo
void makeEnemy(enemy_t e[ENEMYMAX]);


int main(){
    enemy_t enemies[ENEMYMAX];
    makeEnemy(enemies);
    while (1){
        
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
        strncpy(e[i].ship[0], "##", 3);
        strncpy(e[i].ship[1], "##", 3);
    }
}


