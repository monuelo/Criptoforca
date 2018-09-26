/*RSA.c -- */
#include "random_primeGen.h"

#define MAX_PRIME 13 //maior número primo usado pra gerar as chaves


static void publicKeyGen(void) //FALTA CRIAR UMA ESTRUTURA PRA RETORNAR 'E' E 'N'.
{
	//select at random two LARGE prime number p and q.
	int p = rand_prim(MAX_PRIME);
	int q = rand_prim(MAX_PRIME);
	
	int n = p * q;

	//Select a small odd integer 'e' which is relatively prime to (p-1)(q-1)
	int phi = (p - 1)*(q - 1);
	int e = 2;
	while (e < phi)
	{
		// e must be co-prime to phi and
		// smaller than phi.
		if (gcd(e, phi) == 1)
			break;
		else
			e++;

	}

}

// Returns gcd of a and b
static int gcd(int a, int h)
{
	int temp;
	while (1)
	{
		temp = a % h;
		if (temp == 0)
			return h;
		a = h;
		h = temp;
	}
}
