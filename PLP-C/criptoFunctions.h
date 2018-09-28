/*cripto_functions.h -- constantes e declarações para criptoFunctions.c*/

//Definição das constantes
/*ESSES SÃO OS VALORES A SEREM PASSADOS AO CHAMAR A FUNÇÃO CIPHERSTRATEGY(). CADA UM EXECUTA UMA ESTRATÉGIA DE CIFRAGEM DIFERENTE*/
#define SHIFT 0
#define SHUFFLE 1
#define FIBONACCI 2
#define CESAR 3
#define COMPLEMENTAR_ASCII 4
#define CRIPTOMIX 5
// #define RSA 6


char* cipherStrategy(int strategy, char *uncrypted_word);


