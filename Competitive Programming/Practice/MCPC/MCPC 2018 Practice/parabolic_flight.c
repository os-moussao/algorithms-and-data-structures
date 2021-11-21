#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int	main(void)
{
	int	T;

	scanf("%d", &T);

	while (T--)
	{
		int		N;
		double	x, y;

		scanf("%d%lf%lf", &N, &x, &y);
		x /= N * 2;
		printf("%d\n", (int)ceil( 2 *N * sqrt(x*x + y*y)));
	}
}
