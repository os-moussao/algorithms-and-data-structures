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
		int	a, b, c;
		scanf("%d%d%d", &a, &b, &c);

		int	d = abs(a - b);
		if ((a > d && b > d) || (a < d && b < d) || (b == a == d))
			printf("-1\n");
		else if (c >= 1 && c <= d)
			printf("%d\n", c + d);
		else if (c <= 2*d)
			printf("%d\n", c - d);
		else
			printf("-1\n");
	}
}
