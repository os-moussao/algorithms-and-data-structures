//https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/B
#include <stdio.h>

// find the min value >= X
int	find(int *tab, int l, int h, int x)
{
	int	ans = -1;

	while (l <= h)
	{
		int mid = l + (h - l) / 2;
		if (tab[mid] <= x)
		{
			ans = mid;
			l = mid + 1;
		}
		else
			h = mid - 1;
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
