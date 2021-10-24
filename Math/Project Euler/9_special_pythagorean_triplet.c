#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int	main(void)
{
	for (int i = 1; i <= 1000; i++)
	{
		bool	found = false;
		for (int j = 1; j <= 1000; j++)
		{
			double 	sq_sum = i*i + j*j;
			double	sq = sqrt(sq_sum);
			if (sq == (double)ceil(sq) && i + j + sq == 1000)
			{
				found = true;
				printf("%d*%d*%d = %d\n",i, j, (int)sq,  i * j * (int)sq);
				break ;
			}
		}
		if (found)break;
	}
}
