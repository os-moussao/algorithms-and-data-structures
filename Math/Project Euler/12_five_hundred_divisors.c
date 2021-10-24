#include <stdio.h>
#include <math.h>

#define MAX_SIZE 10000

int	divisors(long long val)
{
	int cnt = 2;
	for (int i = 2; i * i <= val; i++)
		if (val % i == 0)
			cnt += 1 + (i * i != val);
	return cnt;
}

int	main(void)
{
	long long	val = 1;
	for (int i = 2; 1; i++)
	{
		val += i;
		if (divisors(val)>=500)
			break ;
	}
	printf("%lld\n", val);
}
