#include <stdio.h>


int	find(int *tab, int l, int h, int x)
{
	int	ans = h + 1;

	while (l <= h)
	{
		int mid = l + (h - l) / 2;

		if (tab[mid] >= x)
			ans = mid,
			h = mid - 1;
		else
			l = mid + 1;
	}

	return (ans + 1);
}

int	main(void)
{
	int	n, k;
	scanf("%d%d", &n, &k);
	int	arr[n];
	for (int i = 0; i < n; i++)
		scanf("%d", arr + i);
	for (int i = 0; i < k; i++)
	{
		int x;
		scanf("%d", &x);
		printf("%d\n", find(arr, 0, n - 1, x));
	}
}

