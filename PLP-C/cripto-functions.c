#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "cripto_functions.h"

//Chama a função de cifragem adequada
//adicionado por Laerson
//Futuramente, seja melhor definir constantes com nomes significativos (ex: #define CESAR1 0), pra passar como argumento
void cipherStrategy(int strategy, char *uncrypted_word)
{
	switch (strategy)
	{
		/*
		implementação será
		case: CIFRAGEM_DO_TIPO_A
		funcao_de_cifragem_do_tipo_a(uncrypted_word);
		*/
	default:
		break;
	}
}

char* shift(char *palavra) {
	char *word = malloc(sizeof(char) * sizeof(palavra));
	strcpy(word, palavra);
	int i = 0;
	while (word[i + 1] != '\0') {
		char swap = word[i];
		word[i] = word[i + 1];
		word[i + 1] = swap;
		i++;
	}
	return word;
}

char* cesar1(char* palavra) {
	char *word = malloc(sizeof(char) * sizeof(palavra));
	strcpy(word, palavra);

	int i = 0;
	while (word[i + 1] != '\0') {
		word[i] = word[i] + 1;
		i++;
	}

	return word;
}

int fibonacciSequence(int n) {
	int auxiliar;
	int a = 1;
	int b = 0;
	for (int i = 0; i < n; i++) {
		auxiliar = a + b;
		a = b;
		b = auxiliar;
	}
	return auxiliar;
}

char* fibonacciCripto(char* palavra) {
	char *word = malloc(sizeof(char) * sizeof(palavra));
	strcpy(word, palavra);
	int i = 0;
	while (word[i + 1] != '\0') {
		word[i] = word[i] + fibonacciSequence(i + 1);
		i++;
	}
	return word;
}

/*int main() {
	char oi[30] = "pipoca";
	printf("shift: %s\n", shift(oi));
	printf("cesar1: %s\n", cesar1(oi));
	printf("fibonacci: %s\n", fibonacciCripto(oi));
	return 0;
}*/ 
