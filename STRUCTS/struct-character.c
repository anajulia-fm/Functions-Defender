
#include<stdio.h>
#include<string.h>


typedef struct{
    char ship[2][5];
    int xasis, yasis, lifes, points;
    /*
        Onde:
          - int xasis -> Posição X do jogador
          - int yasis -> Posiçãp Y do jogador
          - int lifes -> Numero de vidas do jogador
          - int points -> Score do jogador
          - char ship -> Representação do jogador
    */
}player_t;

void mk_player(player_t *p); // Função que define o jogador
void ptr_player(player_t p); // Função que imprime o jogador

int main(){
    player_t player;

    mk_player(&player);

    ptr_player(player);

    return 0;
}

void mk_player(player_t *p){
    // Valores de exemplo:
    p->xasis=0;
    p->yasis=0;
    p->lifes=3;
    p->points=0;
    strncpy(p->ship[0], "@", 5);
    strncpy(p->ship[1], "@@@@", 5);
}

// Função de impressão, meramente para vizualização!!
void ptr_player(player_t p){
    int i;
    printf("\n Eixo X: %d, Eixo Y: %d, Vidas: %d, Pontos: %d\n\n", p.xasis, p.yasis, p.lifes, p.points);
    for(i=0;i<2;i++){
        printf("%s\n", p.ship[i]);
    }
}
