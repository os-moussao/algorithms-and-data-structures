#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>


int	main(void)
{
	long long	T;
	scanf("%lld", &T);

	while (T--)
	{
		long long	x, n;
		scanf("%lld%lld", &x, &n);

		long long res = x;

		for (int i = 1; i < n + 1; i++)
		{
			if (res % 2 == 0)
				res -= i;
			else
				res += i;
		}
		printf("%lld\n", res);
	}
}
