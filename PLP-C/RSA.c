/*RSA.c -- */
#include "randomPrimeGen.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "RSA.h"



static int mdc(int a, int b);
static int ExtEuclid(int a, int b);
static int rsa_modExp(int base, int exponent, int modulus);

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
	int p = rand_prim(MAX_PRIME);
	int q = rand_prim(MAX_PRIME);
	int privateExponent;
	int publicExponent;

	int modulus = p * q;

	//Select a small odd integer, that will be the public key which is relatively prime to (p-1)(q-1)
	int phi = TOTIENT(p, q);
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

	privateExponent = ExtEuclid(phi, publicExponent);
	while (privateExponent < 0) {
		privateExponent += phi;
	}

	pub->modulus = modulus;
	pub->exponent = publicExponent;

	priv->modulus = modulus;
	priv->exponent = privateExponent;

}


// acha o MDC entre A e B
static int mdc(int a, int b)
{
	int temp;
	while (1)
	{
		temp = a % b;
		if (temp == 0)
			return b;
		a = b;
		b = temp;
	}
}

static int ExtEuclid(int a, int b)
{
	int x = 0, y = 1, u = 1, v = 0, gcd = b, m, n, q, r;
	while (a != 0) {
		q = gcd / a; r = gcd % a;
		m = x - u * q; n = y - v * q;
		gcd = a; a = r; x = u; y = v; u = m; v = n;
	}
	return y;
}

static int rsa_modExp(int base, int exponent, int modulus)
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


char *rsa_decrypt(const long long *message,
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
}


