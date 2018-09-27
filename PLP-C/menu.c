#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "menu.h"
#include <ctype.h>
#include <stdbool.h>
#include "criptoFunctions.h"
#include "time.h"

/** prototypes **/

bool usedCheck(char guess, char *word, char *correct, bool containsGuess);
void switchHelp(int option, char *word, char *correct);
static void resetUsedTips();
void getHelp(char *word, char *correct);
void displayTitle();
void clrscreen();
void resetGame();
void showOnPrompt(char *message);
static void resetUsedLetters();

// Helps
static void revealCategoryHelp(char *word);
static void vowelsNumberHelp(char *word);
static void revealLetterHelp(char* word, char* correct);
static void undergradHelp(char* word);

int vowels[5] = {'A', 'E', 'I', 'O', 'U'};
char revealedTip[20];
char VowelsQnt[3];
bool usedTips[4];
char tip[20];
char usedLetters[26];
char prompt[100];
int numUsedLetters = 0;
int erros = 0;
bool used;
char encryptedWord[12];

//For for :P
int i;

void displayTitle()
{
    printf("||##################### #$&!CRIPTOForca#$&! #####################>>");
}

void clrscreen()
{
    system("clear");
    displayTitle();
}

bool isUsed(char letter) {
	for(int i = 0; i < sizeof(usedLetters); i++){
		if(letter == usedLetters[i])
			return true;
	} return false;
}

void getHelp(char *word, char *correct)
{
    clrscreen();
    int opc;

    printf("\n\n Selecione uma Dica: ");
    printf("\n\n [1] - Revelar categoria: ");
    printf("\n\n [2] - Revelar uma letra: ");
    printf("\n\n [3] - Ajuda dos Universitários: ");
    printf("\n\n [4] - Revelar Quantidade de vogais: ");
    printf("\n\n Opção escolhida: ");
    scanf("%d", &opc);

    switchHelp(opc, word, correct);
}

void switchHelp(int option, char *word, char *correct)
{
    if (usedTips[option - 1] == true)
    {
        showOnPrompt("Você já usou isto!");
        return;
    }

    switch (option)
    {
    case 1:
        revealCategoryHelp(word);
        break;
    case 2:
        revealLetterHelp(word, correct);
        break;
    case 3:
        undergradHelp(word);
        break;
    case 4:
        vowelsNumberHelp(word);
        break;
    default:
        switchHelp(option, word, correct);
    }
}

/*** Dicas ***/

static void revealCategoryHelp(char *word)
{
    usedTips[0] = true;
    strcpy(revealedTip, tip);
}

static void revealLetterHelp(char *word, char *correct)
{
    usedTips[1] = true;
    srand (time(NULL));
    int num = rand() % sizeof(word);
    usedCheck(word[num], word, correct, false);
}

static void undergradHelp(char* word)
{
    usedTips[2] = true;
    char text[120];
    sprintf(text, "Hmm... Acho que a palavra é %s", word);
    showOnPrompt(text);
}

static bool isVowel(char letter)
{
    for (int i = 0; i < 5; i++)
    {
        if (letter == vowels[i])
            return true;
    }
    return false;
}

static void vowelsNumberHelp(char *word)
{
    int numVowels = 0;
    for (int i = 0; i < sizeof(word); i++)
    {
        if (isVowel(word[i]))
        {
            numVowels += 1;
        }
    }
    usedTips[3] = true;
    sprintf(VowelsQnt, "%d", numVowels);
}

static void resetUsedTips()
{
    for (int i = 0; i < 4; i++)
    {
        usedTips[i] = false;
    }
}

static void resetUsedLetters()
{
    for (i = 0; i < strlen(usedLetters); i++)
    {
        usedLetters[i] = '*';
    }
}

void resetGame()
{
    resetUsedTips();
    strcpy(VowelsQnt, "**");
    strcpy(revealedTip, "***");
}

void renderMenu(char *correct, char *word)
{
    clrscreen();
    printf("\n||>> Categoria: %s | erros: %d | palavra: %s | Letras usadas: ", revealedTip, erros, encryptedWord);
    for (i = 0; i < numUsedLetters; i++)
    {
        printf("%c ", usedLetters[i]);
    }
    printf("\n||>> Número de Vogais: %s |", VowelsQnt);

    printf("\n||>> Pressione [1] para obter uma Dica | [2] para SAIR --\n||\n");
    printf("|=$ %s\n||\n", prompt);
    displayTitle();
    printf("||\n||\n|/  ");

    for (i = 0; i < strlen(word); i++)
    {
        if (correct[i] == '*')
        {
            printf("_ ");
        }
        else
        {
            printf("%c ", correct[i]);
        }
    }
}

char typeGuess(char guess)
{
    printf("\n\n  Digite seu palpite: ");
    scanf(" %c", &guess);
    guess = toupper(guess);

    strcpy(prompt, "");
    return guess;
}

bool usedCheck(char guess, char *word, char *correct, bool containsGuess)
{
    //checa se a letra já foi usada
    for (i = 0; i < 26; i++)
    {
        if (usedLetters[i] == guess)
        {
            used = true;
        }
    }

    //Se não foi usada
    if (used == false)
    {
        usedLetters[numUsedLetters] = guess;
        numUsedLetters++;

        containsGuess = false;
    }

    //Verifica se a palavra contém o palpite do usuário. A variável contemPalpite é usada para o controle dos erros
    for (i = 0; i < strlen(word); i++)
    {
        if (guess == word[i])
        {
            correct[i] = guess;
            containsGuess = true;
        }
    }

    if (containsGuess == false)
    {
        erros++;
    }
}

int numErros()
{
    return erros;
}

void encryptWord(char *word, int option, char* category)
{
    strcpy(tip, category);
    strcpy(encryptedWord, word);
    strcpy(encryptedWord, "**TEMP**");
    // cypherStrategy(option, encryptedWord);
}

void showOnPrompt(char *message)
{
    strcpy(prompt, message);
}
