#include <stdio.h>
#include <math.h>
#include <stdbool.h>

long long	next_prime(long long p)
{
	int	sq = (int)sqrt(p + 1);
	
	for (int i = 2; i <= sq; i++)
	{
		if ((p + 1) % i == 0)
			return (next_prime(p + 1));
	}
	return (p + 1);
}

long long	nth_prime(int n)
{
	long long p = 2;

	for (int i = 1; i < n; i++)
		p = next_prime(p);
	return (p);
}

int	main(void)
{
	printf("%lld\n", nth_prime(10001));
}
