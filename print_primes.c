#include <stdio.h>
#include <math.h>

int prime(int n)
{
	int i;
	if (n<2)
		return 0;
	if (n==2)
		return 1;
	int raiz = sqrt(n) + 1;
	for(i=2; i<raiz; ++i)
		if (n%i == 0)
			return 0;
	return 1;
}

int main(int argc, char **argv)
{
	long min, max, i;
	int n_primes = 0;

	if (argc == 2)
	{
		min = 2;
		sscanf(argv[1], "%ld", &max);
	}

	else if (argc == 3)
	{
		sscanf(argv[1], "%ld", &min);
		sscanf(argv[2], "%ld", &max);
	}

	printf("All prime numbers between %ld and %ld:\n\n", min, max);

	for (i = min; i <= max; ++i)
		if (prime(i))
		{
			printf("%li, ", i);
			n_primes ++;
		}

		printf("\n\nPrinted %d prime numbers.\n", n_primes);
	return 0;
}