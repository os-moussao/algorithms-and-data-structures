#include <stdio.h>

/*
 * power function exists in c
 * but I prefer to refresh my mind
**/
long long	power(long long b, long long p)
{
	if (p <= 0)
		return (p == 0);
	if (p % 2 == 0)
		return (power(b*b, p / 2));
	else
		return (b * power(b*b, (p - 1) / 2));
}

int	sum_dig(long long nbr)
{
	int	sum = 0;
	while (nbr)
	{
		sum += nbr % 10;
		nbr /= 10;
	}
	return (sum);
}

int	main(void)
{
	printf("%d\n", sum_dig(power(2, 15)));

}
