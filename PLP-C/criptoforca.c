#include <time.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "menu.h"
#include "dollDraw.h"
#include "criptoFunctions.h"

/*** prototypes ***/

/*bool belongs(char letter, char* list) {
	for(int i = 0; i < sizeof(list); i++){
		if(letter == list[i])
			return true;
	} return false;
}*/

int main()
{
	// Number of itens for each category in the game
	const int NUM_ITENS = 20;

	char paises[20][12] = {"ALEMANHA", "BRASIL", "ARGENTINA",
						   "ITALIA", "ESCOCIA", "NIGERIA", "INGLATERRA", "CHINA",
						   "HOLANDA", "AUSTRALIA", "RUSSIA", "CROACIA", "INDIA",
						   "ESPANHA", "DINAMARCA", "CANADA", "EQUADADOR", "MEXICO", "CUBA",
						   "VENEZUELA"};
	char frutas[20][12] = {"JAMBO", "BANANA", "CARAMBOLA", "MELAO", "FIGO",
						   "GOIABA", "JABUTICABA", "KIWI", "LARANJA", "MELANCIA", "MANGA",
						   "MARACUJA", "PESSEGO", "PITOMBA", "BANANA", "TANGERINA", "TOMATE",
						   "TAMARINDO", "UVA", "UMBU"};

	char backMenu;

	//Word to  be encrypted
	char word[12];

	//if correct == word,the player wins.
	char correct[12];

	int i;

	char guess;

	int containsGuess = 0;
	int option = 0;
	int level = 0;

	while (option != 3)
	{

		//Letras usadas pelo usuário e contador de letras usadas para repetições.
		int numUsedLetters = 0;
		int used;

		do
		{

			system("clear");

			clrscreen();
			printf("\n\n Escolha o que deseja fazer: ");
			printf("\n\n 1 - Jogar: ");
			printf("\n\n 2 - Cifrar uma palavra: ");
			printf("\n\n 3 - Sair: ");
			printf("\n\n Opção escolhida: ");
			scanf("%d", &option);

			if (option == 1)
			{

				do
				{
						srand(time(NULL));
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

				switch (level)
				{
				case 1:
					//Seleciona uma palavra aleatória
					strcpy(word, paises[rand() % NUM_ITENS]);
					encryptWord(word, 1, "paises");
					break;
				case 2:
					strcpy(word, frutas[rand() % NUM_ITENS]);
					encryptWord(word, 2, "frutas");
					break;

				default:
					break;
				}
			}
			else if (option == 2)
			{ // need a real fix.

				// printf("\n Digite a palavra para ser cifrada: ");
				// scanf(" %[^\n]", tip);
				// printf("\n Digite a palavra a ser adivinhada: ");
				// scanf(" %[^\n]", word);

				for (i = 0; i < strlen(word); i++)
				{
					word[i] = toupper(word[i]);
				}
			}
			else if (option == 3)
			{
				break;
			}

		} while (option != 1 && option != 2 && option != 3);

		if (option != 3)
		{
			resetGame();

			for (i = 0; i < strlen(word); i++)
			{
				correct[i] = '*';
			}

			correct[strlen(word)] = '\0';

			while (strcmp(word, correct) != 0 && numErros() != 5)
			{
				renderMenu(correct, word);

				if (strcmp(word, correct) != 0 && numErros() != 5)
				{

					used = 0;

					guess = typeGuess(guess);

					// Dica
					if (guess == '1')
					{
						getHelp(word);
					}
					else if (isalpha(guess))
					{
						usedCheck(guess, word, correct, containsGuess);
					}
				}
			}
		}

		if (numErros() == 5)
		{
			printf("\n  YOU LOSE!!!\n  Palavra correta era %s", word);
		}
		else
		{
			printf("\n  YOU WIN!!!\n   Palavra correta era %s", word);
		}

		printf("\n\n Aperte algo para voltar ao menu");
		scanf(" %c", &backMenu);
	}
	return 0;
}
