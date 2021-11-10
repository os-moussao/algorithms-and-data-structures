#include <stdio.h>

// find max in an increasing-decreasing array >>>>>>>max<<<<<<<
int	find(int *tab, int l, int h, int size)
{
	while (l <=	h)
	{
		int mid = l + (h - l) / 2;
		if (mid == 0 || mid == size - 1)
			return (mid);
		if (tab[mid] >= tab[mid - 1] && tab[mid] >= tab[mid + 1])
			return (mid);
		else if (tab[mid + 1] <= tab[mid])
			h = mid - 1;
		else if (tab[mid + 1] >= tab[mid])
			l = mid + 1;
	}
	return (-1);
}

int	main(void)
{
	int	tab[11] = {4, 6, 9, 12, 11, 8, 6, 4, 1, 0, -1};
	int ans;
	if ((ans = find(tab, 0, 10, 11)) == -1)
		printf("no ans!! Really?!!\n");
	else
		printf("max = %d\n", tab[ans]);
}
