
#include<stdio.h>
#include<time.h>
#include<conio.h>
#include<conio2.h>
#include<math.h>
#include<string.h>

#define MAXSPEED 1.25
#define MAXCOORDX 415

// Player:
typedef struct{
    char ship[2][5];
    int staticXAsis, xAsis, yAsis, lifes, points;
    /*
        Onde:
          - int staticXAsis -> Posição x inicial do jogador
          - int xAsis -> Posição X do jogador
          - int yAsis -> Posiçãp Y do jogador
          - int lifes -> Numero de vidas do jogador
          - int points -> Score do jogador
          - char ship -> Representação do jogador
    */
}player_t;

// Função que define o jogador
void makePlayer(player_t *p);
// Função que imprime o jogador
void printPlayer(player_t p);
// Limpa ultima posição do player:
void clearPlayer(player_t p);



int main(){
    // 'PERSONAGENS':
    player_t player;

    // MISCELLANEOUS:
    char c;

    // Temporarias, substituir por leitura de matriz!
    // Encontrar o char '@' e atribuir as cordenadas;
    // ex.: player.yAsis=i, de arquivoMapa[i][j]
    // e player.xAsis=j, da mesma matriz.
    int firstX, firstY;

    // 'FLAGS':
    int dPressedFlag=0, CoolDownFlag=0, CoolDownFlagAux=0;

    // VELOCIDADE DO JOGADOR:
    int coolDown=0;
    float maxSpeed=0;

    // 'TIMERS':
    long double speed=0; // VELOCIDADE DO JOGADOR
    long double start_t=0, end_t=0, total_t=0; // TEMPO DO LAÇO
    long double CoolDownEnd_t, CoolDownAux_t, coolDownChecker_t=0; // TEMPO DE COOLDOWN

    makePlayer(&player);
    maxSpeed=MAXSPEED;


    firstX=10; // Pegar as cordenadas do char '@' no mapa lido
    firstY=10; // Pegar as cordenadas do char '@' no mapa lido
    player.staticXAsis=firstX;
    player.xAsis=firstX;
    player.yAsis=firstY;

    while (1){
        start_t=(double)clock()/CLOCKS_PER_SEC;
        dPressedFlag=0;
        // Leitura de teclado
        if(kbhit()){
            c=getch();
            switch (c){
                // D
                case 'd':
                case 'D':
                case 77: // RIGHT-ARROW
                    dPressedFlag=1;
                    if(coolDown){
                        CoolDownAux_t=start_t;
                    }
                    break;
                // W
                case 'w':
                case 'W':
                case 72:  // UP-ARROW
                    clearPlayer(player);
                    player.yAsis--;
                    printPlayer(player);
                    if(player.yAsis<=1){
                        player.yAsis=1; //Somar 1 no gotoxy(x, y); y=1 => header
                    }
                    break;
                // S
                case 's':
                case 'S':
                case 80: // DOWN-ARROW
                        clearPlayer(player);
                        player.yAsis++;
                        printPlayer(player);
                        if(player.yAsis>=35){
                            player.yAsis=35;
                        }
                    break;
                // A
                case 'a':
                case 'A':
                case 75: // LEFT-ARROW
                    maxSpeed+=0.25;
                    if(maxSpeed>MAXSPEED){
                        maxSpeed=MAXSPEED;
                    }
                    break;
            }
        }
        end_t=(double)clock()/CLOCKS_PER_SEC;
        // Tempo total de execução
        total_t+=(end_t-start_t);
        speed+=(end_t-start_t);
        coolDownChecker_t+=(end_t-start_t);
        // Zera CoolDown
        if (CoolDownAux_t-CoolDownEnd_t>=1){
            CoolDownAux_t=0;
            CoolDownEnd_t=0;
            coolDown=0;
            CoolDownFlag++;
        }
        // Decrementa a velocidade
        if(coolDownChecker_t>=1.5){
            coolDownChecker_t=0;
            if(CoolDownFlag==CoolDownFlagAux){
                maxSpeed+=0.5;
                if(maxSpeed>MAXSPEED){
                    maxSpeed=MAXSPEED;
                }
            }
            CoolDownFlagAux=CoolDownFlag;
        }
        // Incrementa Velocidade
        if(dPressedFlag){
            if(!coolDown){
                maxSpeed-=0.25;
                if(maxSpeed<=0.25){
                    maxSpeed=0.25;
                }
                coolDown=1;
                CoolDownEnd_t=(double)clock()/CLOCKS_PER_SEC;
            }
        }
        // Imprime
        if(speed>=maxSpeed){
            if(maxSpeed!=MAXSPEED){
                // Incrementa posição x da nave
                clearPlayer(player);
                player.xAsis++;
                printPlayer(player);
                gotoxy(1,1);
                printf("(%d, %d)", player.xAsis, player.yAsis);
                if(player.xAsis>=MAXCOORDX){
                    player.xAsis=MAXCOORDX;
                }
                // FUNÇÂO DE IMPRESSAO
            }
            speed=0;
        }
    }


    return 0;
}

// PLAYER:
// Function que limpa a ultima posição do jogador:
void clearPlayer(player_t p){
    gotoxy(p.staticXAsis, p.yAsis);
    printf("    ");
    gotoxy(p.staticXAsis, p.yAsis+1);
    printf("    ");
}
// Cria Jogador:
void makePlayer(player_t *p){
    p->xAsis=0;
    p->yAsis=0;
    p->lifes=3;
    p->points=0;
    strncpy(p->ship[0], "@", 5);
    strncpy(p->ship[1], "@@@@", 5);
}
// Imprime Jogador:
void printPlayer(player_t p){
    int i;
    for(i=0;i<2;i++){
        gotoxy(p.staticXAsis, p.yAsis+i);
        printf("%s", p.ship[i]);
    }
}

//
