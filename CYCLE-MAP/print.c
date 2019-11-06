#include<stdio.h>
#include<conio2.h>
#include<conio.h>
#include<time.h>

#define MXPTR 5   // Limite de impressão
#define MXJU 450 // Valor maximo do J da matrizUniverso
#define MXIU 3  //  Valor maximo do I da matrizUniverso

void mk_u(int matrizUniverso[][MXJU]);

int main(){
    int matrizUniverso[MXIU][MXJU];

    // Variavel que aloca o mapa a ser repitido, neste exemplo '99'
    // representa o char 'C'
    int mapaDoArquivoBinario[3][5]={{1, 2, 3, 4, 5},{0, 0, 0, 0, 99}, {1, 2, 3, 4, 5}};
    
    int i, j, k, l, y;


    int x=0, horaDoLoop=0, endgame=0, flagL=0, tempL=0;

    // As variaveis abaixo são utilizadas UNICAMENTE para automatizar o processo
    // de visualização, totalmente descartáveis...
    long double start_t, end_t, total_t=0;

    mk_u(u);
    while(!endgame){
        start_t=(double)clock()/CLOCKS_PER_SEC;
        y=0;
        for(j=0+x, l=tempL; j<MXPTR+x;j++){
            if(horaDoLoop){
                l=0;
            }
            horaDoLoop=0;
            for(i=0, k=0;i<3;i++, k++){
                if(matrizUniverso[i][j]==100){
                    if(mapaDoArquivoBinario[k][l]==99){
                        matrizUniverso[i][j]=0;
                        horaDoLoop=1;
                    }else{
                        matrizUniverso[i][j]=mapaDoArquivoBinario[k][l];
                    }
                    flagL=1;
                }
                gotoxy(y+5, i+5);
                printf("%d", matrizUniverso[i][j]);
            }
            if(flagL&&!horaDoLoop){
                l++;
            }
            flagL=0;
            y++;
        }
        tempL=l;
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
