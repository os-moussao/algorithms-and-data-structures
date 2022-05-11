// https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/A
#include <stdio.h>

int	find(long long *tab, long long l, long long h, long long x)
{
	while (l <= h)
	{
		// l + h might overflow, so avoid using the formula (l + h) / 2 
		// mid = l + (h - l) / 2;   middle (rounding down)
		// mid = l + (h - l + 1) / 2;  middle (rounding up)
		long long	mid = l + (h - l) / 2;
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
	int	n, k;
	scanf("%d%d", &n, &k);
	long long	arr[n];
	for (int i = 0; i < n; i++)
		scanf("%lld", arr + i);
	for (int i = 0; i < k; i++)
	{
		long long x;
		scanf("%lld", &x);
		printf("%s\n", find(arr, 0, n - 1, x)?"YES":"NO");
	}
}
