#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>

int	main(void)
{
	//FILE	*in = freopen("f.in", "r", stdin);
	int	T;

	scanf("%d", &T);
	while (T-- > 0)
	{
		int	a, b;

		scanf("%d%d", &a, &b);
		printf("%d\n", a+b);
	}
}
