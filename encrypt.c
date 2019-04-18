#include <stdio.h>
#include "algorithms.h"

long encrypt(char chr, long N, long e)
{
	long tmp_msg = (long)chr, final_msg = 1, i;

	for (i = 0; e > 0; ++i) {
		if (e%2)
			final_msg = (final_msg * tmp_msg) % N;
		e /= 2;
		tmp_msg = (tmp_msg * tmp_msg) % N;
	}
	return final_msg;
}
int main()
{
	long N, e;
	char original[MAX_MSG];
	long encrypted[MAX_MSG], i, size;

	printf("Public key > ");
	scanf("%ld %ld", &N, &e);

	printf("Message: \n> ");
	getchar();
	scanf("%[^\n]s", original);
	
	for (i = 0; original[i] != '\0'; ++i)
	{
		encrypted[i] = encrypt(original[i], N, e);
	}

	size = i + 1;

	puts("\nEncrypted message:");
	for (i = 0; i < size; ++i)
		printf("%ld ", encrypted[i]);
	printf("\n");
	return 0;

}