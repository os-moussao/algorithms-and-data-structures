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

		int	sq = (int)floor(sqrt(n));
		int	i = 1, j = sq + 1;
		int	val = sq*sq + 1;

		if (sq*sq == n)
		{
			printf("%d 1\n", sq);
			continue ;
		}

		while (val < n && i < j)
			val++, i++;
		while (val < n && j > 1)
			val++, j--;

		printf("%d %d\n", i, j);
	}
}
