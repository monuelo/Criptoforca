#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include "fileHandler.h"

/*** prototypes ***/

/*** Data ***/

const int NUM_ITENS = 20;

char currentCategory[20];

char paises[20][12] = {"ALEMANHA", "BRASIL", "ARGENTINA",
                       "ITALIA", "ESCOCIA", "NIGERIA", "INGLATERRA", "CHINA",
                       "HOLANDA", "AUSTRALIA", "RUSSIA", "CROACIA", "INDIA",
                       "ESPANHA", "DINAMARCA", "CANADA", "EQUADOR", "MEXICO", "CUBA",
                       "VENEZUELA"};
char frutas[20][12] = {"JAMBO", "BANANA", "CARAMBOLA", "MELAO", "FIGO",
                       "GOIABA", "JABUTICABA", "KIWI", "LARANJA", "MELANCIA", "MANGA",
                       "MARACUJA", "PESSEGO", "PITOMBA", "BANANA", "TANGERINA", "TOMATE",
                       "TAMARINDO", "UVA", "UMBU"};

char animais[20][12] = {"LEAO", "JACARE", "TARTARUGA", "PEIXE", "GATO",
                        "LAGARTIXA", "CACHORRO", "PINGUIM", "PASSARO", "ZEBRA",
                        "HIPOPOTAMO", "LOBO", "RINOCERONTE", "PORCO", "GALINHA",
                        "ABELHA", "FORMIGA", "MACACO", "ESQUILO", "CORUJA"};

char profissoes[20][12] = {"MEDICO", "ENGENHEIRO", "BOMBEIRO", "CIENTISTA", "ADVOGADO",
                           "DESIGNER", "PROFESSOR", "DENTISTA", "JUIZ", "ECONOMISTA",
                           "FOTOGRAFO", "GERENTE", "CANTOR", "ANALISTA", "CONTADOR",
                           "PROGRAMADOR", "HISTORIADOR", "REPORTER", "ARQUITETO", "POLITICO"};

char comida[20][12] = {"PIZZA", "HAMBURGUER", "FEIJAO", "ARROZ", "BATATA",
                       "BOLO", "CHOCOLATE", "IOGURTE", "LEITE", "MANDIOCA",
                       "PAO", "TORRADA", "BROWNIE", "SANDUICHE", "SORVETE",
                       "QUIABO", "SUSHI", "PASTEL", "COXINHA", "EMPADA"};

static void selectWord(int option, char word[12])
{
    switch (option)
    {
    case 0:
        strcpy(word, paises[rand() % NUM_ITENS]);
        strcpy(currentCategory, "paises");
        break;

    case 1:
        strcpy(word, frutas[rand() % NUM_ITENS]);
        strcpy(currentCategory, "frutas");
        break;

    case 2:
        strcpy(word, animais[rand() % NUM_ITENS]);
        strcpy(currentCategory, "animais");
        break;

    case 3:
        strcpy(word, profissoes[rand() % NUM_ITENS]);
        strcpy(currentCategory, "profissoes");
        break;

    case 4:
        strcpy(word, comida[rand() % NUM_ITENS]);
        strcpy(currentCategory, "comida");
        break;
    }
}

void randomWord(char word[12]) {
    srand(time(NULL));
    int category = rand() % 5;
    selectWord(category, word);
}

void catchCurrentCategory(char category[20]) {
    strcpy(category, currentCategory);
}