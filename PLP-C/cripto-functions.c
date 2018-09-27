#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "criptoFunctions.h"
#include "RSA.h"

static int fibonacciSequence(int n);

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

char* rsa(char* palavra) {
	int messageSize = sizeof(palavra);

	/*char *word = malloc(sizeof(char) * sizeof(palavra));
	strcpy(word, palavra);*/

	struct public_key_class pub[1];
	struct private_key_class priv[1];

	void keyGen(struct public_key_class *pub, struct private_key_class *priv);
	long long cifra = rsa_encrypt(palavra, messageSize, pub);

	char cifraString[sizeof(cifra)];
	sprintf(cifraString, "%lld", cifra);

	return cifraString;
}

static int fibonacciSequence(int n) {
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
/**
 * complementarAscii: substitui cada caractere pelo seu complementar da tabela AscII. Exemplo: AscII de 'A' é 65,
 * logo, seu complementar é 127-65 = 62.
 * PS.: Os caracteres de códigos complementares entre 0 e 31 sao deslocados 31 caracteres para frente
 */
char* complementarAscii(char* palavra) {
	char *word = malloc(sizeof(char) * strlen(palavra));
	for (int i = 0; i < strlen(palavra); i++) {
		int codeAsc = (127 - (int)palavra[i]);
		if (codeAsc < 31)
			codeAsc += 31;
		word[i] = (char)codeAsc;
	}
	return word;
}

/**
 * checkIndex:  auxiliar de shuffle
 */
int checkIndex(int j, int* indices, int size) {
	for (int i = 0; i < size; i++)
		if (j == indices[i]) {	// se o indice j ja foi utilizado, test = 1
			return 1;
		}
	return 0;
}
/**
 * shuffle:  criptografia para embaralhar as letras da string
 */
char* shuffle(char* palavra) {
	srand(time(NULL));
	char *word = malloc(sizeof(char) * strlen(palavra));
	int *indices = malloc(sizeof(int)* strlen(palavra));

	for (int i = 0; i < strlen(palavra); i++)
		indices[i] = -1;

	for (int i = 0; i < strlen(palavra); i++) {
		int j = rand() % strlen(palavra);
		int test = checkIndex(j, indices, strlen(palavra));

		if (test == 0) {
			word[j] = palavra[i];
			indices[i] = j;
		}
		else
			i--;
	}
	return word;
}

/**
 * criptoMix: realiza 4 criptografias em sequencia para a mesma palavra
 */
char* criptoMix(char* palavra) {
	char *word = malloc(sizeof(char) * strlen(palavra));
	word = shuffle(palavra);
	word = cesar1(word);
	word = complementarAscii(word);
	word = fibonacciCripto(word);

	return word;
}


/*int main() {
	char oi[30] = "pipoca";
	printf("shift: %s\n", shift(oi));
	printf("cesar1: %s\n", cesar1(oi));
	printf("fibonacci: %s\n", fibonacciCripto(oi));
	printf("shuffle: %s\n", shuffle(oi));
	printf("complementarAscii: %s\n", complementarAscii(oi));
	printf("Criptomix: %s\n", criptomix(oi));
	return 0;
}*/
