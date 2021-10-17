#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <math.h>
#include <limits.h>

int	main(void)
{
	FILE	*fp = freopen("input.in", "r", stdin);
	int	T;

	scanf("%d", &T);
	while (T-- > 0)
	{
		// process
	}
	fclose(fp);
}
