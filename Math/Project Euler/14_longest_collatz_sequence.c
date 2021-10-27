#include <stdio.h>

long long unsigned int	count_terms(long long unsigned int n)
{
	long long unsigned int	cnt = 0;

	while (n > 1)
	{
		if (n % 2 == 0)
			n /= 2;
		else
			n = 3*n + 1;
		cnt++;
	}
	return (cnt);
}

int	main(void)
{
	int	max = -1;
	int	index;
	int	cnt;
	for (int n = 2; n <= 1000000; n++)
		if ((cnt = count_terms((long long unsigned int)n)) > max)
			max = cnt, index = n;
	printf("%d\n", index);
}
