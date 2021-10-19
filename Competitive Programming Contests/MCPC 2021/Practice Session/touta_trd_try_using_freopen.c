#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <math.h>
#include <limits.h>

int	main(void)
{
	FILE	*fp = freopen("eat.in", "r", stdin);
	int	T;

	scanf("%d", &T);
	while (T-- > 0)
	{
		long long int	a, b;

		scanf("%ld%ld", &a, &b);
		printf("Plate %d\n", a + b> a*b? 1: 2);
	}
	fclose(fp);
}
