#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

int	main(void)
{
	int	T;

	scanf("%d", &T);
	for (int t = 0; t < T; t++)
	{
		int		N;
		double	ith_before = 0;
		double	ith = 0;
		double	Q = 10;
		double	max = INT_MIN;
		int		ith_max = 1;

		scanf("%d", &N);
		for (int i = 1; i <= N; i++)
		{
			ith_before = ith;
			ith = (Q * i) / N;
			Q -= ith;
			if (ith_before > ith)
				break ;
			if (ith > max)
			{
				max = ith;
				ith_max = i;
			}
		}
		printf("%d\n", ith_max);
	}
}
