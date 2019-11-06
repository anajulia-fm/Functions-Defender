#include<stdio.h>
#include<conio2.h>
#include<conio.h>
#include<time.h>

#define MXPTR 5
#define MXJU 450
#define MXIU 3

void mk_u(int matrizUniverso[][MXJU]);

int main(){
    int matrizUniverso[MXIU][MXJU];
    int mapaDoArquivoBinario[3][5]={{1, 2, 3, 4, 5},{0, 0, 0, 0, 99}, {1, 2, 3, 4, 5}};
    int i, j, k, l, y;
    int x=0, flag=0, endgame=0, lflag=0, z=0;
    long double start_t, end_t, total_t=0;

    mk_u(u);
    while(!endgame){
        start_t=(double)clock()/CLOCKS_PER_SEC;
        y=0;
        for(j=0+x, l=z; j<MXPTR+x;j++){
            if(flag){
                l=0;
            }
            flag=0;
            for(i=0, k=0;i<3;i++, k++){
                if(matrizUniverso[i][j]==100){
                    if(mapaDoArquivoBinario[k][l]==99){
                        matrizUniverso[i][j]=0;
                        flag=1;
                    }else{
                        matrizUniverso[i][j]=mapaDoArquivoBinario[k][l];
                    }
                    lflag=1;
                }
                gotoxy(y+5, i+5);
                printf("%d", matrizUniverso[i][j]);
            }
            if(lflag&&!flag){
                l++;
            }
            lflag=0;
            y++;
        }
        z=l;
        end_t=(double)clock()/CLOCKS_PER_SEC;
        total_t+=(end_t-start_t);

        if(total_t>=2){
            x++;
            total_t=0;
            clrscr();
        }
        if(MXPTR+x==MXJU){
            endgame=1;
        }
    }

return 0;
}

void mk_u(int matrizUniverso[][MXJU]){
    int i, j;

    for(i=0;i<MXIU;i++){
        for(j=0;j<MXJU;j++){
            *(matrizUniverso[0]+i*MXJU+j)=100;
        }
    }
}
