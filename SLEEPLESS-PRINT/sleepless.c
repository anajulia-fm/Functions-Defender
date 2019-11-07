
#include<stdio.h>
#include<time.h>
#include<conio.h>
#include<conio2.h>
#include<math.h>

#define MAXSPEED 50

void teste();

int main(){
    char c;
    int dPressedFlag=0, firstTimeFlag=1; // Flags
    int speed=0, maxSpeed, speedCounter=0;  // VELOCIDADE
    long double endKeyBoard_t=0, totalKeyBoard_t=0, auxKeyBoard_t=0; // TEMPO DE KBHIT
    long double start_t=0, end_t=0, total_t=0, aux_t=0; // TEMPO DO LAÇO

    while (1)
    {
        start_t=(double)clock()/CLOCKS_PER_SEC;
        if(kbhit()){
            c=getch();
            switch (c)
            {
                case 'd':
                    if(firstTimeFlag){
                        auxKeyBoard_t=start_t;
                        firstTimeFlag=0;
                    }
                    endKeyBoard_t=(double)clock()/CLOCKS_PER_SEC;
                    dPressedFlag=1;
                    break;
                default:
                    dPressedFlag=0;
            }
        }
        if(dPressedFlag){
            totalKeyBoard_t=(endKeyBoard_t-auxKeyBoard_t);
            gotoxy(1,1);
            printf("\n TOTAL: %Lf,\n START: %Lf,\n END: %Lf,\n AUX: %Lf", (double)totalKeyBoard_t, (double)start_t, (double)endKeyBoard_t, (double)auxKeyBoard_t);
        }
        if(totalKeyBoard_t>=0.1){
            speed+=10;
            if(speed>MAXSPEED){
                speed=MAXSPEED;
            }
            auxKeyBoard_t=start_t;
        }
        end_t=(double)clock()/CLOCKS_PER_SEC;
        total_t+=(end_t-start_t);
        if (total_t>=1){
            if(totalKeyBoard_t==aux_t){
                endKeyBoard_t=0;
                auxKeyBoard_t=0;
                firstTimeFlag=1;
                maxSpeed+=15;
                if(maxSpeed>MAXSPEED){
                    maxSpeed=MAXSPEED;
                }
                speed-=10;
                if(speed<0){
                    speed=0;
                }
            }
            aux_t=totalKeyBoard_t;
            gotoxy(1, 11);
            printf("MAXSPEED: %d, SPEED: %d, TOTAL: %d", maxSpeed, speed, maxSpeed-speed);
            total_t=0;
        }
        if(maxSpeed-speed<=0){
            gotoxy(1, 10);
            teste();
            gotoxy(1, 11);
            printf("MAXSPEED: %d, SPEED: %d, TOTAL: %d", maxSpeed, speed, maxSpeed-speed);
            speedCounter++;
            if(speedCounter==2){
                maxSpeed-=10;
                if(maxSpeed<10){
                    maxSpeed=10;
                }
                speedCounter=0;
            }
            speed=0;
        }
    }


    return 0;
}

void teste(){
    static int i;

    printf("%d", i);
    i++;
}
