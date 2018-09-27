/*cripto_functions.h -- constantes e declarações para criptoFunctions.c*/

//Definição das constantes
/*ESSES SÃO OS VALORES A SEREM PASSADOS AO CHAMAR A FUNÇÃO CIPHERSTRATEGY(). CADA UM EXECUTA UMA ESTRATÉGIA DE CIFRAGEM DIFERENTE*/
#define CESAR 0
#define SHIFT 1
#define FIBONACCI 2
#define RSA 3
#define COMPLEMENTAR_ASCII 4
#define SHUFFLE 5
#define CRIPTOMIX 6




void cipherStrategy(int strategy, char *uncrypted_word);


