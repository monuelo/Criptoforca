#include "menu.h"
#include <time.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "dollDraw.h"
#include "fileHandler.h"
#include "criptoFunctions.h"

static void wordstrcpy(char *newWord);

int main()
{

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
		do
		{

			system("clear");

			clrscreen();
			printf("||\n||\n||\n");			
			printLogo();
			printf("||\n||\n||\n||\t\tEscolha o que deseja fazer: ");
			printf("\n||\n||\t\t1 - Jogar: ");
			printf("\n||\n||\t\t2 - Cifrar uma palavra: ");
			printf("\n||\n||\t\t3 - Sair: ");
			printf("\n||\n||");
			printf("\n||\n||");
			printf("\n||\n||\nO=================> Opção escolhida: ");
			scanf("%d", &option);

			if (option == 1)
			{

				do
				{
					srand(time(NULL));
					resetGame();
					clrscreen();
					printf("||\n||\n||\n");
					printf("||\n||\n||\t\tEscolha o nivel para jogar: ");
					printf("\n||\n||\n||\n||");
					printf("\n||\n||\t\t1 - Rasgado: ");
					printf("\n||\n||\t\t2 - Facil: ");
					printf("\n||\n||\t\t3 - Medio: ");
					printf("\n||\n||\t\t4 - Enigma: ");
					printf("\n||\n||");
					printf("\n||\n||");
					printf("\n||\n||");
					printf("\n||\n||");
					printf("\n||\n||\nO=================> Nível escolhido: ");
					scanf(" %d", &level);

				} while (level < 1 || level > 4);

				char category[20];
				randomWord(word);
				catchCurrentCategory(category);

				switch (level)
				{
				case 1:
					encryptWord(word, 0, category);
					break;
				case 2:
					encryptWord(word, (1 + rand() % 3), category);
					break;
					(1 + rand() % 3);
				case 3:
					encryptWord(word, (3 + rand() % 5), category);
					break;
				case 4:
					encryptWord(word, 5, category);
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
					guess = typeGuess(guess);

					// Dica
					if (guess == '1')
					{
						getHelp(word, correct);
					}
					else if (guess == '2')
					{
						clrscreen();
						printf("\n||\n||\t\tDeseja Realmente Sair??");
						printf("\n||\n||\t\t[1] - Sim | Não - [2]\n||\n");
						displayTitle();
						scanf("%s", &guess);
						if (guess == '1')
						{
							break;
						}
						else if (guess == '2')
						{
							continue;
						}
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
			throwLose();
			renderMenu(correct, word);
			printf("\n  YOU LOSE!!!\n  Palavra correta era %s", word);
		}
		else if (strcmp(word, correct) == 0)
		{
			if (level == 4)
			{
				system("clear");
				displayTitle();
				printTuring();
				printf("\n\t\t\t\tUAU! o.o\n\t\t\tTemos um Turing Aqui! ");
			}
			else
			{

				throwSave();
				renderMenu(correct, word);
				printf("\n  YOU WIN!!!\n   Palavra correta era %s", word);
			}
		}

		printf("\n\n--@ Pressione uma tecla para sair...");
		getchar();
		getchar();
	}
	return 0;
}