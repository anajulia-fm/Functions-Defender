
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<conio2.h>

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
// Limpa ultima posição do player:
void clearPlayer(player_t p);

int main(){
    player_t player;
    char c;
    int flag;

    mk_player(&player);
    while (1)
    {
        flag=0;
        c=getch();
        if(c=='d'){
            clearPlayer(player);
            player.xasis++;
            c='z';
            flag=1;
        }else if(c=='a'){
            clearPlayer(player);
            player.xasis--;
            c='z';
            flag=1;
        }else if(c=='w'){
            clearPlayer(player);
            player.yasis--;
            c='z';
            flag=1;
        }else if(c=='s'){
            clearPlayer(player);
            player.yasis++;
            c='z';
            flag=1;
        }
        if(flag){
            ptr_player(player);
        }
    }


    return 0;
}

void mk_player(player_t *p){
    // Valores de exemplo:
    p->xasis=10;
    p->yasis=10;
    p->lifes=3;
    p->points=0;
    strncpy(p->ship[0], "@", 5);
    strncpy(p->ship[1], "@@@@", 5);
}

// Função de impressão, meramente para vizualização!!
void ptr_player(player_t p){
    int i;

    gotoxy(p.xasis, p.yasis-1);
    printf("%s", p.ship[0]);
    gotoxy(p.xasis, p.yasis);
    printf("%s\n", p.ship[1]);
}

// Function que limpa a ultima posição do jogador:
void clearPlayer(player_t p){
    gotoxy(p.xasis, p.yasis-1);
    printf(" ");
    gotoxy(p.xasis, p.yasis);
    printf("    ");
}
