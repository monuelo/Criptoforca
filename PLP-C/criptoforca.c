#include <time.h>
#include <stdio.h>
#include <ctype.h>
#include <unistd.h> 
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "dollDraw.h"
#include "cripto_functions.h"

int vowels[5] = {'A', 'E', 'I', 'O', 'U'}; 
char usedLetters[26];
bool usedTips[4];
char prompt[30];

//Tip
char tip[20];
char revealedTip[20];

struct gameConfig {
	int attemps;
	int currentLevel;
	char* currentWord;
};

bool belongs(char letter, char* list) {
	for(int i = 0; i < sizeof(list); i++){
		if(letter == list[i])
			return true;
	} return false;
}

struct gameConfig Match;

typedef struct cipherType {
	char* type;
	char* description;
} cipherType;

char VowelsQnt[3];

/*** prototypes ***/
void switchHelp(int option, char* word);

/*** vectors ***/
char* words[0];
char* exampleWords[0];
cipherType cipherTypes[0];

void displayTitle(){
	printf("||##################### #$&!CRIPTOForca#$&! #####################>>");
}

void clrscreen(){
	system("clear");
	displayTitle();
}


void getHelp(char* word){
	clrscreen();
	int opc;

	printf("\n\n Selecione uma Dica: ");
			printf("\n\n [1] - Revelar categoria: ");
			printf("\n\n [2] - Revelar uma letra: ");
			printf("\n\n [3] - Ajuda dos Universitários: ");
			printf("\n\n [4] - Revelar Quantidade de vogais: ");
			printf("\n\n Opção escolhida: ");
			scanf("%d", &opc);

	switchHelp(opc, word);
}


/*** Dicas ***/

void revealCategory(char* word) {
	usedTips[0] = true;
	strcpy(revealedTip, tip);
}

void revealWord() {
	// TODO
}
 
void undergradHelp() {
	// todo
}

bool isVowel(char letter) {
	for(int i = 0; i < 5; i++){
		if(letter == vowels[i])
			return true;
	} return false;
}

void vowelsNumber(char* word) {
	int numVowels = 0;
	for(int i=0; i < sizeof(word); i++){
		if(isVowel(word[i])) {
			numVowels += 1;
		}
	}
	usedTips[3] = true;
	sprintf(VowelsQnt, "%d", numVowels);
}

void showOnPrompt(char* message){
	strcpy(prompt, message);
}

void switchHelp(int option, char* word) {
	if (usedTips[option - 1] == true){
		showOnPrompt("Você já usou isto!");
		return;
	}

	switch(option){
		case 1:
			revealCategory(word);
			break;
		case 2:
			revealWord();
			break;
		case 3:
			undergradHelp();
			break;
		case 4:
			vowelsNumber(word);
			break;
		default:
			return switchHelp(option, word);
			
	}
}

int main() {

	// Number of itens for each category in the game
	const int NUM_ITENS = 20;

	
	char paises[20][12] = { "ALEMANHA", "BRASIL", "ARGENTINA",
			"ITALIA", "ESCOCIA", "NIGERIA", "INGLATERRA", "CHINA",
			"HOLANDA", "AUSTRALIA", "RUSSIA", "CROACIA", "INDIA",
			"ESPANHA", "DINAMARCA", "CANADA", "EQUADADOR", "MEXICO", "CUBA",
			"VENEZUELA" };
	char frutas[20][12] = { "JAMBO", "BANANA", "CARAMBOLA", "MELAO", "FIGO",
			"GOIABA", "JABUTICABA", "KIWI", "LARANJA", "MELANCIA", "MANGA",
			"MARACUJA", "PESSEGO", "PITOMBA", "BANANA", "TANGERINA", "TOMATE",
			"TAMARINDO", "UVA", "UMBU" };
	

	//For for :P
	int i;


	char backMenu;

	//Word to  be encrypted
	char word[12];

	//if correct == word,the player wins.
	char correct[12];


	char guess;


	int containsGuess = 0;
	int option = 0;
	int level = 0;


	while (option != 3) {
		strcpy(VowelsQnt, "**");
		strcpy(revealedTip, "***");
		
		usedTips[0] = false;
		usedTips[1] = false;
		usedTips[2] = false;
		usedTips[3] = false;
		
		//Letras usadas pelo usuário e contador de letras usadas para repetições.
		int numUsedLetters = 0;
		int used;

		int erros = 0;

		do {

			system("clear");


			for (i = 0; i < strlen(usedLetters); i++) {
				usedLetters[i] = '*';
			}

			clrscreen();
			printf("\n\n Escolha o que deseja fazer: ");
			printf("\n\n 1 - Jogar: ");
			printf("\n\n 2 - Cifrar uma palavra: ");
			printf("\n\n 3 - Sair: ");
			printf("\n\n Opção escolhida: ");
			scanf("%d", &option);

			if (option == 1) {

				do {

					system("clear");

					clrscreen();
					printf("\n\n Escolha o nivel para jogar: ");
					printf("\n\n 1 - Rasgado: ");
					printf("\n\n 2 - Facil: ");
					printf("\n\n 3 - Medio: ");
					printf("\n\n 4 - Enigma: ");
					printf("\n\n Nível escolhido: ");
					scanf(" %d", &level);

				} while (level < 1 || level > 4);


				srand(time(NULL));

				switch (level) {
				case 1:
					strcpy(tip, "paises");
					//Seleciona uma palavra aleatória
					strcpy(word, paises[rand() % NUM_ITENS]);
					break;
				case 2:
					strcpy(tip, "frutas");
					strcpy(word, frutas[rand() % NUM_ITENS]);
					break;
				
				default:
					break;
				}


			} else if (option == 2) { // need a real fix.

				printf("\n Digite a palavra para ser cifrada: ");
				scanf(" %[^\n]", tip);
				printf("\n Digite a palavra a ser adivinhada: ");
				scanf(" %[^\n]", word);

				for (i = 0; i < strlen(word); i++) {
					word[i] = toupper(word[i]);
				}

			} else if (option == 3) {
				break;
			}

		} while (option != 1 && option != 2 && option != 3);

		if (option != 3) {


			for (i = 0; i < strlen(word); i++) {
				correct[i] = '*';
			}

			correct[strlen(word)] = '\0';

			while (strcmp(word, correct) != 0 && erros != 5) {

				system("clear");

				clrscreen();
				printf("\n||>> Categoria: %s | erros: %d | palavra: %s | Letras usadas: ", revealedTip, erros, word);
				for (i = 0; i < numUsedLetters; i++) {
					printf("%c ", usedLetters[i]);

				}
				printf("\n||>> Número de Vogais: %s |", VowelsQnt);

				printf("\n||>> Pressione [1] para obter uma Dica\n||\n");
				printf("|=$ %s\n||\n", prompt);
				displayTitle();
				printf("||\n||\n|/  ");

				for (i = 0; i < strlen(word); i++) {
					if (correct[i] == '*') {
						printf("_ ");
					} else {
						printf("%c ", correct[i]);
					}
				}

				if (strcmp(word, correct) != 0 && erros != 5) {

					used = 0;

					printf("\n\n  Digite seu palpite: ");
					scanf(" %c", &guess);
					guess = toupper(guess);

					strcpy(prompt, "");

					// Dica	
					if(guess == '1'){
						getHelp(word);
					} else if (isalpha(guess)) {


					//checa se a letra já foi usada
					for (i = 0; i < 26; i++) {
						if (usedLetters[i] == guess) {
							used = 1;
						}
					}

					//Se não foi usada
					if (used == 0) {
						usedLetters[numUsedLetters] = guess;
						numUsedLetters++;

						containsGuess = 0;

						//Verifica se a palavra contém o palpite do usuário. A variável contemPalpite é usada para o controle dos erros
						for (i = 0; i < strlen(word); i++) {
							if (guess == word[i]) {
								correct[i] = guess;
								containsGuess = 1;
							}
						}

						if (containsGuess == 0) {
							erros++;
						}
					}
					}

				}

			}

			if (erros == 5) {
				printf("\n  YOU LOSE!!!\n  Palavra correta era %s", word);
			} else {
				printf("\n  YOU WIN!!!\n   Palavra correta era %s", word);
			}

			printf("\n\n Aperte algo para voltar ao menu");
			scanf(" %c", &backMenu);
		}

	}

	return 0;
}
