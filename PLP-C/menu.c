#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "menu.h"
#include <ctype.h>
#include <stdbool.h>
#include "criptoFunctions.h"

/** prototypes **/

void switchHelp(int option, char *word);
static void resetUsedTips();
void getHelp(char *word);
void displayTitle();
void clrscreen();
void resetGame();
void showOnPrompt(char *message);
static void resetUsedLetters();

// Helps
static void revealCategoryHelp(char *word);
static void vowelsNumberHelp(char *word);
static void revealLetterHelp();
static void undergradHelp();

int vowels[5] = {'A', 'E', 'I', 'O', 'U'};
char revealedTip[20];
char VowelsQnt[3];
bool usedTips[4];
char tip[20];
char usedLetters[26];
char prompt[30];
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

void getHelp(char *word)
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

    switchHelp(opc, word);
}

void switchHelp(int option, char *word)
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
        revealLetterHelp();
        break;
    case 3:
        undergradHelp();
        break;
    case 4:
        vowelsNumberHelp(word);
        break;
    default:
        return switchHelp(option, word);
    }
}

/*** Dicas ***/

static void revealCategoryHelp(char *word)
{
    usedTips[0] = true;
    strcpy(revealedTip, tip);
}

static void revealLetterHelp()
{
    // TODO
}

static void undergradHelp()
{
    // todo
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
    printf("\n||>> Categoria: %s | erros: %d | palavra: %s | Letras usadas: ", revealedTip, erros, word);
    for (i = 0; i < numUsedLetters; i++)
    {
        printf("%c ", usedLetters[i]);
    }
    printf("\n||>> Número de Vogais: %s |", VowelsQnt);

    printf("\n||>> Pressione [1] para obter uma Dica\n||\n");
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
    // cypherStrategy(option, encryptedWord);
}

void showOnPrompt(char *message)
{
    strcpy(prompt, message);
}
