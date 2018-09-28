#include "time.h"
#include "menu.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "dollDraw.h"
#include "criptoFunctions.h"

/** prototypes **/

bool usedCheck(char guess, char *word, char *correct, bool containsGuess);
void switchHelp(int option, char *word, char *correct);
static void resetUsedTips();
void getHelp(char *word, char *correct);
void displayTitle();
void clrscreen();
void resetGame();
void showOnPrompt(const char *message);
static void resetUsedLetters();
void encryptWord(char *word, int option, char category[20]);

// Helps
static void revealCategoryHelp(char *word);
static void vowelsNumberHelp(char *word);
static void revealLetterHelp(char *word, char *correct);
static void undergradHelp(char *word);

/* vowels */
int vowels[5] = {'A', 'E', 'I', 'O', 'U'};
char VowelsQnt[3];

/* Tips */
char revealedTip[20];
bool usedTips[4];
char tip[20];

/* Letters */
int numUsedLetters = 0;
char usedLetters[26];

/* general */
char encryptedWord[12];
char prompt[100];
int erros = 0;
int i;

void displayTitle()
{
    printf("O############################## #$&!CRIPTOForca#$&! ##############################>>\n");
}

void clrscreen()
{
    system("clear");
    displayTitle();
}

bool isUsed(char letter)
{
    for (int i = 0; i < sizeof(usedLetters); i++)
    {
        if (letter == usedLetters[i])
            return true;
    }
    return false;
}

void getHelp(char *word, char *correct)
{
    clrscreen();
    int opc;

    printf("||\n||\n||\t\t Selecione uma Dica: ");
    printf("\n||\n||\t\t [1] - Revelar categoria: ");
    printf("\n||\n||\t\t [2] - Revelar uma letra: ");
    printf("\n||\n||\t\t [3] - Ajuda dos Universitários: ");
    printf("\n||\n||\t\t [4] - Revelar Quantidade de vogais: ");
    printf("\n||\n||\nO=039o22039rjdm00xnB(#NE0)$$$> Opção escolhida: ");
    scanf("%d", &opc);
    
    if(opc < 1 || opc > 4){
        showOnPrompt("Por favor, insira uma entrada válida!");
        return;
    }
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
    usedTips[0] = false;
    strcpy(revealedTip, tip);
}

static void revealLetterHelp(char *word, char *correct)
{
    usedTips[1] = true;
    srand(time(NULL));
    int num = rand() % sizeof(word);
    usedCheck(word[num], word, correct, false);
}

static void undergradHelp(char *word)
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
    erros = 0;
    resetUsedTips();
    strcpy(tip, "");
    resetUsedLetters();
    numUsedLetters = 0;
    strcpy(VowelsQnt, "**");
    strcpy(encryptedWord, "");
    strcpy(revealedTip, "***");
    showOnPrompt("Bem Vindo à CriptoForca!");
}

void renderMenu(char *correct, char *word)
{
    clrscreen();
    printf("||\n||>> Categoria: %s | erros: %d | palavra: %s | Letras usadas: ", revealedTip, erros, encryptedWord);
    for (i = 0; i < numUsedLetters; i++)
    {
        printf("%c ", usedLetters[i]);
    }
    printf("\n||>> Número de Vogais: %s |", VowelsQnt);

    printf("\n||>> Pressione [1] para obter uma Dica | [2] para SAIR --\n||\n");
    printf("|=$ %s\n||\n", prompt);
    displayTitle();
    printf("||\n||\n||  ");
    printf("\t\t\t\t");
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
    printDoll_state(erros);
}

char typeGuess(char guess)
{
    printf("||\n||\nO==15$I(@)*=ode0i49u83heebdg3289j0r%&*@**)83=> Digite seu palpite: ");
    scanf(" %c", &guess);
    guess = toupper(guess);

    strcpy(prompt, "");
    return guess;
}

bool usedCheck(char guess, char *word, char *correct, bool containsGuess)
{

    bool used;

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

    if (containsGuess == false && used == false)
    {
        erros++;
    }
}

int numErros()
{
    return erros;
}

void encryptWord(char *word, int option, char category[20])
{
    strcpy(tip, category);
    strcpy(encryptedWord, word);
    strcpy(encryptedWord, cipherStrategy(option, encryptedWord));
}

void showOnPrompt(const char *message)
{
    strcpy(prompt, message);
}

void throwLose()
{
    erros = 6;
}

void throwSave()
{
    erros = 7;
}