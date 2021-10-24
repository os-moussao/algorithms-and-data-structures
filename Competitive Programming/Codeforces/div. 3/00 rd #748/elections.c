#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

int	max(int a, int  b, int c)
{
	if (a > b && a > c)
		return 0;
	int	max = b > c? b: c;
	return max - a + 1;
}

int	main(void)
{
	int	T;

	scanf("%d", &T);
	while (T-- > 0)
	{
		int	a, b, c;

		scanf("%d%d%d", &a, &b, &c);
		printf("%d %d %d\n", max(a, b, c), max(b, a, c), max(c, a, b));
	}
}

/**
 * max(0, max(b, c) + 1 - a)
**/
