#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void recebePalavra(void);
void limpaTela(void);
void escreveLetras(char entrada[20], int linha,char aux[20]);
void mostraDesenho(int valor);


void mostraDesenho(int valor) {


    switch(valor) {

    case 1:
        printf("____\n");
        printf("|   | \n");
        printf("|   0 \n");
        printf("|  /O\\ \n");
        printf("|   i \n");
        printf("|  / \\ \n");
        printf("_________");
        break;

    case 2:
        printf("____\n");
        printf("|   | \n");
        printf("|   0 \n");
        printf("|  /O\\ \n");
        printf("|   i \n");
        printf("|  /  \n");
        printf("_________");
        break;

    case 3:
        printf("____\n");
        printf("|   | \n");
        printf("|   0 \n");
        printf("|  /O\\ \n");
        printf("|   i \n");
        printf("|     \n");
        printf("_________");
        break;

    case 4:
        printf("____\n");
        printf("|   | \n");
        printf("|   0 \n");
        printf("|  /O  \n");
        printf("|   i  \n");
        printf("|     \n");
        printf("_________");
        break;

    case 5:
        printf("____\n");
        printf("|   | \n");
        printf("|   0 \n");
        printf("|   O \n");
        printf("|   i \n");
        printf("|     \n");
        printf("_________");
        break;

    case 6:
        printf("____\n");
        printf("|   | \n");
        printf("|   0 \n");
        printf("|     \n");
        printf("|      \n");
        printf("|     \n");
        printf("_________");
        break;


    case 7:
        printf("____\n");
        printf("|   | \n");
        printf("|     \n");
        printf("|     \n");
        printf("|      \n");
        printf("|     \n");
        printf("_________");
        break; 

	default: 
		printf("Voce perdeu!\n");

    }


}
void escreveLetras(char entrada[20], int linha, char aux[20]) {
    int i,aux1,p,k=0,aux3 = 1;
    int chances = 1;
    int acert = 0;
    char compar[1];
    char guesses[6];
    char acertos[20];
    int digito = 1;
    int aux4 = 0;
    int contacer = 0;
    int contaerro = 0; 
	 
    while( chances != 7) {


        aux1 = 0;

        mostraDesenho(aux3);
        printf("\n");


        scanf("%s", compar);
		

        limpaTela();


        int teste = 0;
        for(i = 0; i < 20; i++) {

            if(compar[0] == acertos[i]) {
                acertos[i] = '\0';
                teste = 1;
            }
	    
           
        }

        if(teste == 1) {
            printf("Você já digitou: %c\n", compar[0]);

        }

        for(i = 0; i < linha; i++) { //compara



            if(compar[0] == entrada[i]) {

                aux[i] = compar[0];

                aux1 = 1;

                acert++;

		aux4 = 1;

		
		
            } //fim do if

        }

        if(aux1 == 1) { //acertos

            acertos[k] = compar[0];
            k++;



        }


        printf("Seus acertos: "); //mostra acertos

	 
		
	if(aux4 == 1) {

		contacer++;       
		
	}

	      for(i = 0; i < contacer; i++){	
               printf(" %c", acertos[i]);

		//contador do acertp
        	} 


        printf("\n\n ");



        if( aux1 == 0) { //tentativas

            guesses[p] = compar[0];

            chances ++;

            aux3++;

            p++;

        }

        printf("Suas tentativas: ");

	if(aux1 == 0) {        

		contaerro++;

        } 

		
	for(int i = 0; i < contaerro; i++) {

            printf(" %c", guesses[i]);
	
	
	}

	

        printf("\n\n");

        for(i = 0; i < linha; i++) { //printa linha

            printf(" %c ", aux[i]);


        }

        printf("\n\n");

        if(acert == linha) {
            chances = 7;

            printf("\nVocê venceu!!!\n");

        } 

		digito++;
	
    }//fim do while


}

void limpaTela(void) {
    int limp;




    for(limp = 0; limp < 50; limp++) {

        printf("\n");

    }




}

void recebePalava(void) {

    int i;

    char vet[20] = {'-','-','-','-','-','-','-','-','-','-','-','-','-','-'};

    int linha;
    char entrada[20];



    printf("Digite sua palavra\n");
    scanf("%s", entrada);

    linha = strlen(entrada);



    limpaTela();


    for(i = 0; i < linha; i++) {

        printf(" %c", vet[i]);

    }

    printf("\n");



    escreveLetras(entrada, linha,vet);



}



int main(void) {
    printf("Forca Versão 1.0 - Rodrigo\n");
    printf(" ___________________________\n");
    printf("|Bem-vindo ao jogo Da forca:|\n");
    printf(".---------------------------.\n");

    recebePalava();

    return 0;


}
