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

int	main(void)
{
	int p = 2;
	long long sum;

	while (p < 2000000)
		sum += p, p = next_prime(p);
	printf("%lld\n", sum);
}
