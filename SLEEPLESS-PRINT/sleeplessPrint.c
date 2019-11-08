
#include<stdio.h>
#include<time.h>
#include<conio.h>
#include<conio2.h>
#include<math.h>

#define MAXSPEED 1.25

void teste();

int main(){
    char c;
    int dPressedFlag=0, CoolDownFlag=0, CoolDownFlagAux=0; // Flags
    int coolDown=0;  // VELOCIDADE
    float maxSpeed=0;
    long double speed=0; //Velocidade
    long double start_t=0, end_t=0, total_t=0; // TEMPO DO LAÇO
    long double endKeyBoard_t=0, totalKeyBoard_t=0, auxKeyBoard_t=0, aux_t=0; // TEMPO DE KBHIT
    long double CoolDownEnd_t, CoolDownAux_t, coolDownChecker_t=0; // Tempo de CoolDown

    maxSpeed=MAXSPEED;
    while (1)
    {
        dPressedFlag=0;
        start_t=(double)clock()/CLOCKS_PER_SEC;
        if(kbhit()){
            c=getch();
            switch (c)
            {
                case 'd':
                    dPressedFlag=1;
                    if(coolDown){
                        CoolDownAux_t=start_t;
                    }
                    break;

                default:
                    dPressedFlag=0;
            }
        }

        end_t=(double)clock()/CLOCKS_PER_SEC;
        // Tempo total de execução
        total_t+=(end_t-start_t);
        speed+=(end_t-start_t);
        coolDownChecker_t+=(end_t-start_t);
        // Zera CoolDown
        if (CoolDownAux_t-CoolDownEnd_t>=0.3){
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
                if(maxSpeed<0.25){
                    maxSpeed=0.35;
                }
                coolDown=1;
                CoolDownEnd_t=(double)clock()/CLOCKS_PER_SEC;
            }
        }
        // Imprime
        if(speed>=maxSpeed){
            if(maxSpeed!=MAXSPEED){
                teste();
            }
            speed=0;
        }
    }


    return 0;
}

void teste(){
    static int i;

    gotoxy(1, 1);
    printf("%d", i);
    i++;
}
