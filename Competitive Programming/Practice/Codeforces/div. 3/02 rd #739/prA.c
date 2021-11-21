#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>

int	main(void)
{
	int	T;
	scanf("%d", &T);

	while (T--)
	{
		int	n;
		scanf("%d", &n);

		long long	res = 1;
		while (--n)
		{
			res++;
			while (res % 3 == 0 || res % 10 == 3)
				res++;
		}
		printf("%lld\n", res);
	}
}
