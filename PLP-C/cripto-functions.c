#include<stdio.h>
#include<string.h>
#include <stdlib.h>

char* shift(char *palavra) {
    char *word = malloc (sizeof (char) * sizeof(palavra));
    strcpy(word, palavra);
    int i = 0;
    while(word[i+1] != '\0') {
        char swap = word[i];
        word[i] = word[i+1];
        word[i+1] = swap;
        i++;
    }
    return word;
}

char* cesar1(char* palavra) {
    char *word = malloc (sizeof (char) * sizeof(palavra));
    strcpy(word, palavra);

    int i = 0;
    while(word[i+1] != '\0') {
        word[i] = word[i] + 1;
        i++;
    }

    return word;
}

int fibonacciSequence(int n) {
    int auxiliar;
    int a = 1;
    int b = 0;
    for(int i = 0; i < n; i++) {
        auxiliar = a + b;
        a = b;
        b = auxiliar;
    }
    return auxiliar;
}

char* fibonacciCripto(char* palavra) {
    char *word = malloc (sizeof (char) * sizeof(palavra));
    strcpy(word, palavra);
    int i = 0;
    while(word[i+1] != '\0') {
        word[i] = word[i] + fibonacciSequence(i+1);
        i++;
    }
    return word;
}

int main() {
    char oi[30] = "pipoca";
    printf("shift: %s\n", shift(oi));
    printf("cesar1: %s\n", cesar1(oi));
    printf("fibonacci: %s\n", fibonacciCripto(oi));
    return 0;
}