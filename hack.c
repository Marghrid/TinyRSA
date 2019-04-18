#include <stdio.h>
#include "algorithms.h"

int get_key(int N, int e)
{
	int p, q;

	p = least_prime_factor(N);
	q = N/p;

	printf("Prime numbers: %d & %d\n", p, q);

	return modular_inverse(e, (p-1) * (q-1));
}

long decrypt(long init_msg, long N, long e_til)
{
	long final_msg = 1, i;

	for (i = 0; e_til; ++i)
	{
		if (e_til % 2)
			final_msg = (final_msg * init_msg) % N;
		e_til /= 2;
		init_msg = (init_msg * init_msg) % N;
	}
	return final_msg;
}

int main()
{
	long N, e, encrypted = 1, i=0;
	char message[MAX_MSG];

	printf("Shame on you, Eve!!\n\nPublic key > ");
	scanf("%ld %ld", &N, &e);

	e = get_key(N, e);

	printf("\nEncrypted message:\n > ");


	while(1)
	{
		scanf("%ld", &encrypted);
		if(encrypted == -1 || encrypted == 0) break;
		message[i++] = (char) decrypt(encrypted, N, e);
	}
	message[i] = '\0';
	printf("\nDecrypted message:\n\t'%s'\n", message);
	return 0;
}