#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <math.h>
#include <limits.h>

int	main(void)
{
	FILE	*in = freopen("f.in", "r", stdin);
	FILE	*out = freopen("f.out", "w", stdout);
	int	T;

	scanf("%d", &T);
	while (T-- > 0)
	{
		int	a, b;

		scanf("%d%d", &a, &b);
		printf("%d\n", a+b);
	}
	fclose(in);
	fclose(out);
}
