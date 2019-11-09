
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<conio2.h>

#define ENEMYMAX 20

// Enemy:
typedef struct{
    int active, xAsis, yAsis, lifes, printFlag;
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
    int mat[35][75]={110000000000000000000000000000000000000000000000000000000000000111111111111, 011000000000000000011111000000000000000000000000000000000000011100000000000, 001111110000000000110001100000000000000000000000000000001111110000000000000, 000000011110000011100000110000000000000001111000000000111000000000000000000, 000000000011111110000000010000000000000111001100000011100000000000000000000, 000000000000000000000000011111111100001100000111111110000000000000000000000, 000000000000000000000000000000000111111000000000000000000000000000000000000, 000000000000000000000000000000000000000000000000000000000000000000000000000, 000000000000000000000000000000000000000000000000000000000000000000000000000, 000000000000000000000000000000000000000000000000000000000000000000000000000, 000000000000000000000000000000000000000000000000000000000000000000000000000, 000000000000000000000000000000000000000000000000000000000000000000000000000, 000000000000000000000000000000000000000000000000000000000000000000000000000, 000000000000000000000000000000000000000000000000000000000000000000000000000, 000000000000000000000000000000000000000000000000000000000000000000000000000, 000000000000000000000000000000000000000000000000000000000000000000000000000, 000000000000000000000000000000000000000000000000000000000000000000000000000, 000000000000000000000000000000000000000000000000000000000000000000000000000, 000000000000000000000000000000000000000000000000000000000000000000000000000, 000000000000000000000000000000000000000000000000000000000000000000000000000, 000000000000000000000000000000000000000000000000000000000000000000000000000, 000000000000000000000000000000000000000000000000000000000000000000000000000, 000000000000000000000000000000000000000000000000000000000000000000000000000, 000000000000000000000000000000000000000000000000000000000000000000000000000, 000000000000000000000000000000000000000000000000000000000000000000000000000, 000000000000000000000000000000000000000000000000000000000000000000000000000, 000000000000000000000000000000000000000000000000000000000000000000000000000, 000000000000000000000000000000000000000000000000000000000000000000000000000, 000000000000000000000000000000000000000000000000000000000000000000000000000, 000000000001111111000000000000000000000000000000000000000000000000000000000, 000111111111000001000000000000000000000000000000000001000000000000000000000, 111100000000000001100000000000000000000000000000000110100000000000000000011, 000000000000000000111000000000000000000000000000001100110000000000000000110, 000000000000000000001100000000000000000000000000011000011111111111111111100, 000000000000000000000111111111111111111111111111110000000000000000000000000};

    makeEnemy(enemies);

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


