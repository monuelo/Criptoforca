/*random_PrimeGen.c -- Gerador de números primos pseudoaleatórios*/

#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include "randomPrimeGen.h"

static int rand_lim(int limit);
static bool primeCheck(int n);

static int rand_lim(int limit) {
	// retorna um número aleatório, entre 0, e limit (inclusivo)
	 

	int divisor = RAND_MAX / (limit + 1);
	int retval;

	do {
		retval = rand() / divisor;
	} while (retval > limit);

	return retval;
}

static bool primeCheck(int n) {
	//checa se um n é primo
	if (n <= 1) {
		return false;
	}

	if ((n == 2)) {
		return true;
	}

	if ((n % 2) == 0) {
		return false;
	}

	int i;
	for (i = 3; i < n; i++) {
		if ((n % i) == 0) {
			return false;
		}
	}

	return true;
}

int rand_prim(int limit) {
	//retorna um número primo menor igual a limit

	int prime;

	do {
		prime = rand_lim(limit);
	} while (!primeCheck(prime));

	return prime;
}

