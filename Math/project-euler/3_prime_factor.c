#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool	is_prime(long long nbr)
{
	long long sq = (long long)sqrt(nbr);
	
	for (long long i = 2; i < sq; i++)
	{
		if (nbr % i == 0)
			return (false);
	}
	return (true);
}

long long	next_prime(long long n)
{
	if (is_prime(n + 1))
		return (n + 1);
	return next_prime(n + 1);
}

int	main(void)
{
	long long p = 2;
	long long nbr = 600851475143;

	while (nbr > 1) // the last peice will always be a prime so the program will not quit
	{
		if (nbr % p == 0)
			printf("%lld * ", p), nbr /= p;
		else
			p = next_prime(p);
	}
	printf("%lld", p);
}
