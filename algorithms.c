#include <stdio.h>
#include <math.h>
#include "algorithms.h"

int euclides(int a, int b)
{
	int rem = 1;
	if (a < 0)
		a = -a;

	if (b < 0)
		b = -b;

	if (a < b)
		swap(a, b);

	if (!b)
		return a;

	else
		while (rem)
		{
			rem = a % b;
			a = b;
			b = rem;
		}
		
		return a;
}

int saunderson(int a, int b, int bezout[])
{
	int rem = 1, quociente;
	int ca_1 = 1, ca_0 = 0, cb_1 = 0, cb_0 = 1, tmp;

	if (a<b)
		swap(a, b);

	if (!b)
		return a;

	else
		while (rem)
		{
			quociente = a / b;
			tmp = ca_0;
			ca_0 = ca_1 - (ca_0 * quociente);
			ca_1 = tmp;
			tmp = cb_0;
			cb_0 = cb_1 - (cb_0 * quociente);
			cb_1 = tmp;
			rem = a % b;
			a = b;
			b = rem;
		}

		bezout[0] = ca_1;
		bezout[1] = cb_1;

		return a;
}

int relative_primes(int a, int b)
{
	return euclides(a, b) == 1;
}

int modular_inverse(int num, long modulo)
{
	int bezout[2];
	
	if (relative_primes(num, modulo))
	{
		while(num > modulo)
			num -= modulo;
		saunderson(modulo, num, bezout);
		while (bezout[1]<0)
			bezout[1] += modulo;
		return bezout[1] % modulo;
	}

	else
		return -1;
}

int least_prime_factor(int n)
{
	int i = -1;
	while(n % primes_list[++i] != 0);
	return primes_list[i];
}