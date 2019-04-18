#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "algorithms.h"

int main()
{	
	srand (time(NULL));
	long p, q, n, m, d, e;

	do
	{
		p = primes_list[(rand() % (MAX_PRIME + 1) )];
		q = primes_list[(rand() % (MAX_PRIME + 1) )];
		printf("P: %ld,   Q: %ld\n", p, q);
	} while(p==q || p*q < 255255);

	n = p*q;
	m = (p-1)*(q-1);

	e = primes_list[rand() % 23 + 1];
	d = modular_inverse(e, m);

	if(d==-1)
		puts("\n\nSomething went wrong");

	if (e>d)
		swap (e, d);

	printf("New private key:  <%ld %ld>\n",n, d);
	printf("New public key:   <%ld %ld>\n",n, e);

	return 0;
}