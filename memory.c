#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 4

void geraMatriz(int m[MAX][MAX]);
void embaralhaMatriz(int m[MAX][MAX]);
void mostraMatriz(int m[MAX][MAX]);
void temporizador(void);
void jogoMatriz(int m[MAX][MAX]);

void temporizador(void) {

    int aux;
    aux = 1;
    while(aux < 100) {

        printf("\n");
        aux++;

    }
}



void jogoMatriz(int m[MAX][MAX]) {

    int  linha, coluna, aux[MAX][MAX],aux1[16],aux2 = 0;

    int e[MAX][MAX],i,j;

    int entrada;
    int linha1[16];
    int coluna1[16];
    int testador,s,s1,t,t1,aux3;
    int x = 0,y = 0;
    int ganho = 1;
    printf("Você está pronto?\nDigite - 1 Se sim\n");

    scanf("%d", &entrada);

    if(entrada == 1) {

        temporizador();

    }


    for(i = 0; i < MAX; i++) {

        for(j = 0; j < MAX; j++) {

            e[i][j] = 0;
            aux[i][j] = 0;

        }

    }

    mostraMatriz(e);

    temporizador();

    while(x != 5) {

        while(y < 2) {

            printf("Digite uma linha e digite uma coluna!\n");
            scanf("%d", &linha);
            scanf("%d", &coluna);
            linha1[aux2] = linha-1;
            coluna1[aux2] = coluna-1;

            e[linha-1][coluna-1] = m[linha-1][coluna-1];
            aux1[aux2] = m[linha-1][coluna-1];

            aux2++;

            y++;

            temporizador();
            mostraMatriz(e);
        }
        y = 0;

        temporizador();

        if(aux1[aux2-1] != aux1[aux2-2]) {

            s = linha1[aux2-1];
            s1 = linha1[aux2-2];
            t = coluna1[aux2-1];
            t1 = coluna1[aux2-2];

            e[s][t] = 0;
            e[s1][t1] = 0;

            x++;

            printf("Você errou!\nChances restantes [%d]\n",5-x);

        } else {
            printf("Você Acertou!\nChances restantes [%d]\n",5-x);

            if(ganho == 8) {
                printf("Você venceu!!\n");

            }

            ganho++;
        }

        mostraMatriz(e);



    }//fim do while
}

void mostraMatriz(int m[MAX][MAX]) {
    int i,j;


    printf("\n");

    for(i = 0; i < MAX; i++) {

        for(j = 0; j < MAX; j++) {

            printf(" %d ", m[i][j]);

        }

        printf("\n");

    }
}

void embaralhaMatriz(int m[MAX][MAX]) {

    srand(time(NULL));

    int i,j,r,y,aux;

    for ( i = 0; i < MAX; i++) {
        for ( j = 0; j < MAX; j++) {
            r = rand() % MAX;
            y = rand() % MAX;
            aux = m[i][j];
            m[i][j] = m[r][y];
            m[r][y] = aux;
        }
    }

}

void geraMatriz(int m[MAX][MAX]) {

    int i,j,v;

    v = 1;

    for(j = 0; j < MAX; j++) {

        for(i = 0; i < MAX; i++) {

            m[i][j] = v++;

            if( v == 9) v = 1;

        }

    }

}

int main(void) {
    int m[MAX][MAX];

    printf(" ___________________________\n");
    printf(":Bem-vindo ao jogo da memória:\n");
    printf(" ----------------------------\n");
    geraMatriz(m);
    embaralhaMatriz(m);
    mostraMatriz(m);
    jogoMatriz(m);

    return 0;

}
