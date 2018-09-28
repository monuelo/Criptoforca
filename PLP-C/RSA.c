/*RSA.c -- */
#include "randomPrimeGen.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "RSA.h"



static long long mdc(long long a, long long b);
static long long ExtEuclid(long long a, long long b);
static long long modularMultiplicativeInverse(long long a, long long mod);
static long long rsa_modExp(long long base, long long exponent, long long modulus);
static long long mmc(long long a, long long b);

/*
struct public_key_class {
	int modulus;
	int exponent;
};
struct private_key_class {
	int modulus;
	int exponent;
}; */


void keyGen(struct public_key_class *pub, struct private_key_class *priv) //gera chaves públicas e privadas
{
	//select at random two LARGE prime number p and q.
	long long p = randPrim(MAX_PRIME);
	long long q = randPrim(MAX_PRIME);
	long long privateExponent;
	long long publicExponent;

	long long modulus = p * q;

	//Select a small odd integer, that will be the public key which is relatively prime to (p-1)(q-1)
	long long phi = mmc((p-1), (q-1));

	publicExponent = 2;
	while (publicExponent < phi)
	{
		// publicKey must be co-prime to phi and
		// smaller than phi.
		if (mdc(publicExponent, phi) == 1)
			break;
		else
			publicExponent++;

	}

	privateExponent = modularMultiplicativeInverse(publicExponent, phi);

	pub->modulus = modulus;
	pub->exponent = publicExponent;

	priv->modulus = modulus;
	priv->exponent = privateExponent;

}


static long long mmc(long long a, long long b) {
	return  (a*b) / mdc(a, b);
}

// acha o MDC entre A e B
static long long mdc(long long a, long long b)
{
	long long temp;
	while (1)
	{
		temp = a % b;
		if (temp == 0)
			return b;
		a = b;
		b = temp;
	}
}


static long long ExtEuclid(long long a, long long b)
{
	long long x = 0, y = 1, u = 1, v = 0, gcd = b, m, n, q, r;
	while (a != 0) {
		q = gcd / a; r = gcd % a;
		m = x - u * q; n = y - v * q;
		gcd = a; a = r; x = u; y = v; u = m; v = n;
	}
	return y;
} 

static long long modularMultiplicativeInverse(long long a, long long mod) {
	//aX + my = 1
	//aX = 1  - my
	long long y = ExtEuclid(a, mod);
	long long x = (1 - mod * y) / a;
	while (x <= 0) {
		x += mod;
	}
	return x;
}


static long long rsa_modExp(long long base, long long exponent, long long modulus)
{
	if (base < 0 || exponent < 0 || modulus <= 0) {
		exit(1);
	}
	base = base % modulus;
	if (exponent == 0) return 1;
	if (exponent == 1) return base;
	if (exponent % 2 == 0) {
		return (rsa_modExp(base * base % modulus, exponent / 2, modulus) % modulus);
	}
	if (exponent % 2 == 1) {
		return (base * rsa_modExp(base, (exponent - 1), modulus) % modulus);
	}

}


/*trecho de codigo do https://github.com/andrewkiluk/RSA-Library/blob/master/rsa.c */
long long *rsa_encrypt(const char *message, const unsigned long message_size, const struct public_key_class *public)
{
	long long *encrypted = malloc(sizeof(long long)*message_size);
	if (encrypted == NULL) {
		fprintf(stderr,
			"Error: Heap allocation failed.\n");
		return NULL;
	}
	long long i = 0;
	for (i = 0; i < message_size; i++) {
		encrypted[i] = rsa_modExp(message[i], public->exponent, public->modulus);
	}
	return encrypted;
} 


/*char *rsa_decrypt(const long long *message,
	const unsigned long message_size,
	const struct private_key_class *priv)
{
	if (message_size % sizeof(long long) != 0) {
		fprintf(stderr,
			"Error: message_size is not divisible by %d, so cannot be output of rsa_encrypt\n", (int)sizeof(long long));
		return NULL;
	}
	// We allocate space to do the decryption (temp) and space for the output as a char array
	// (decrypted)
	char *decrypted = malloc(message_size / sizeof(long long));
	char *temp = malloc(message_size);
	if ((decrypted == NULL) || (temp == NULL)) {
		fprintf(stderr,
			"Error: Heap allocation failed.\n");
		return NULL;
	}
	// Now we go through each 8-byte chunk and decrypt it.
	long long i = 0;
	for (i = 0; i < message_size / 8; i++) {
		temp[i] = rsa_modExp(message[i], priv->exponent, priv->modulus);
	}
	// The result should be a number in the char range, which gives back the original byte.
	// We put that into decrypted, then return.
	for (i = 0; i < message_size / 8; i++) {
		decrypted[i] = temp[i];
	}
	free(temp);
	return decrypted;
} */
