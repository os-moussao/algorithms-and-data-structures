#include <stdio.h>

int	find(int *tab, int l, int h, int x)
{
	while (l <= h)
	{
		// l + h might overflow, so avoid using the formula (l + h) / 2 
		// mid = l + (h - l) / 2;   middle (rounding down)
		// mid = l + (h - l + 1) / 2;  middle (rounding up)
		int	mid = l + (h - l) / 2;
		if (tab[mid] == x)
			return 1;
		else if (tab[mid] < x)
			l = mid + 1;
		else
			h = mid - 1;
	}
	return (0);
}

int	main(void)
{
	int	tab[] = {-1, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	printf("%d\n", find(tab, 0, 9, 0));
}
