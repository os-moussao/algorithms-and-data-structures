#include <stdio.h>

double	os_sqrt(double x)
{
	if (x < 0)
		return (-1);
	double	mid, l = 0, h = x, eps = 0.000001;
	while (h - l > eps)
	{
		mid = l + (h - l) / 2;
		if (mid*mid < x)
			l = mid;
		else
			h = mid;
	}
	return (mid);
}

int	main(void)
{
	printf("%lf", os_sqrt(2));
}
