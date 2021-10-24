#include <stdio.h>
#include <math.h>

int revnbr(int nbr)
{
	int rev = 0;

	while (nbr)
	{
		rev = rev * 10 + nbr % 10;
		nbr /= 10;
	}
	return (rev);
}

int	main(void)
{
	int max = -1;
	for (int i = 999; i >= 100; i--)
	{
		for (int j = i; j >= 100; j--)
		{
			int nbr = i * j;
			if (nbr == revnbr(nbr) && nbr > max)
				max = nbr;
		}
	}
	printf("%d\n", max);
	return 1;
}
