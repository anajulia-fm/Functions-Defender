
#include<stdio.h>
#include<time.h>
#include<conio.h>
#include<conio2.h>

int main(){
    char c;
    int dPressedFlag=0, firstTimeFlag=1;
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
        // if(totalKeyBoard_t>=3){
        //     auxKeyBoard_t=start_t;
        // }
        end_t=(double)clock()/CLOCKS_PER_SEC;
        total_t+=(end_t-start_t);
        if (total_t>=1){
            total_t=0;
            if(totalKeyBoard_t==aux_t){
                endKeyBoard_t=0;
                auxKeyBoard_t=0;
                firstTimeFlag=1;
            }
            aux_t=totalKeyBoard_t;
        }


    }


    return 0;
}
