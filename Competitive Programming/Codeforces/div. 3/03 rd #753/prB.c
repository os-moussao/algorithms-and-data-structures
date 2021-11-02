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

		if (x % 2 == 0)
			x += 3 * (n / 3) * (n / 3 + 1) - 3 + (n * (n % 3 == 1)), x -= 3 * (n / 3) * (n / 3 + 1) / 2;
		else
			x -= 3 * (n / 3) * (n / 3 + 1) - 3 + (n * (n % 3 == 1)), x += 3 * (n / 3) * (n / 3 + 1) / 2;

		printf("%lld\n", x );
	}
}
