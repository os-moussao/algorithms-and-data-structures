#include <stdio.h>

// find the min value >= X
int	find(int *tab, int l, int h, int x)
{
	int	ans = -1;

	while (l <= h)
	{
		int mid = l + (h - l) / 2;
		if (tab[mid] == x)
			return (mid);
		else if (tab[mid] >= x)
		{
			ans = mid;
			h = mid - 1;
		}
		else if (tab[mid] < x)
			l = mid + 1;
	}
	return (ans);
}

int	main(void)
{
	int	tab[10] = {1, 2, 3, 5, 6, 7, 8, 10, 12};
	for (int i = 0; i < 9; i++)
		printf("%d	", tab[i]);
	printf("\n");
	int	ans;
	if ((ans = find(tab, 0, 8, 4)) == -1)
		printf("no answer found\n");
	else
		printf("ans = %d\n", tab[ans]);
}
