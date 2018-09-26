#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "dollDraw.h"
#include "cripto_functions.h"



struct gameConfig {
	int attemps;
	int currentLevel;
	char* currentWord;
};

struct gameConfig Match;

typedef struct cipherType {
	char* type;
	char* description;
} cipherType;

/*** vectors ***/
char* words[0];
char* exampleWords[0];
cipherType cipherTypes[0];


void getHelp(){
	
	int opc;

	printf("\n\n Selecione uma Dica: ");
			printf("\n\n [1] - Revelar categoria: ");
			printf("\n\n [2] - Revelar uma letra: ");
			printf("\n\n [3] - Ajuda dos Universitários: ");
			printf("\n\n [4] - Quantidade de vogais: ");
			printf("\n\n Opção escolhida: ");
			scanf("%d", &opc);

}


/*** Dicas ***/

void revealCategory() {
	// TODO	
}

void revealWord() {
	// TODO
}

void undergradHelp() {
	// todo
}

void vowelsNumber() {
	// TODO
}


void countVowelNumber() {
	// TODO
}


void switchHelp(int option) {
	switch(option){
		case 1:
			revealCategory();
		case 2:
			revealWord();
		case 3:
			undergradHelp();
		case 4:
			vowelsNumber();
		default:
			return switchHelp(option);
	}
}

#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <time.h>

int main() {


int option;
int level;

while (option != 3) {


printf("!#$$CriptoForca$!#$");
printf("\n\n Bem vindo! Escolha uma das opcoes abaixo!: ");
printf("\n\n 1 - Jogar ");
printf("\n\n 2 - Informacoes: ");
printf("\n\n 3 - Sair: ");
printf("\n\n Digite opcao escolhida: ");
scanf("%d", &option);

if ( option == 1) {


printf("\n!#$$CriptoForca$!#$\n");
printf("\n\n Bem vindo! Escolha um dos niveis abaixo!: ");
printf("\n\n 1 - Rasgado ");
printf("\n\n 2 - Facil: ");
printf("\n\n 3 - Medio: ");
printf("\n\n 4 - Enigma: ");
scanf("%d", &level);



 while (level < 1 || level > 5);

				//Para gerar números aleatórios
				srand(time(NULL));

				switch (level) {
				case 1:
					printf("\n\n 1 - Rasgado ");

// a preguica consome, colocar as funcoes aqui e chamar.
					break;
				case 2:
					printf("\n\n 2 - Facil: ");;
					break;
				case 3:
					printf("\n\n 3 - Medio: ");
					break;
				case 4:
					printf("\n\n 4 - Enigma: ");
					break;
				
				default:
					break;
				}



}


else if (option == 2) {
printf("\n\n Projeto de PLP 2018.2 - CriptoForca ");
printf("\n\n Equipe composta por:");
printf("\n\n Explicacao, agora volte e va jogar (: \n\n");
}



}

	return 0;
}



