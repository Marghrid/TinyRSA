#include <stdio.h>
#include "algorithms.h"

long decrypt(long init_msg, long N, long e_til)
{
	long final_msg = 1, i;

	for (i = 0; e_til; ++i)
	{
		if (e_til%2)
			final_msg = (final_msg * init_msg) % N;
		e_til /= 2;
		init_msg = (init_msg * init_msg) % N;
	}
	return final_msg;
}

int main()
{
	long N, e_til, encrypted, i = 0;
	char message[MAX_MSG];

	printf("Private key > ");
	scanf("%ld %ld", &N, &e_til);

	printf("Encrypted message:\n> ");

	while (1)
	{
		scanf("%ld", &encrypted);
		if(encrypted == -1 || encrypted == 0) break;
		message[i++] = (char) decrypt(encrypted, N, e_til);
	}
	message[i] = '\0';
	printf("\nDecrypted message:\n\t'%s'\n", message);
	
	return 0;
}