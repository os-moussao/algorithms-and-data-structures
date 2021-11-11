// https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/D
#include <iostream>
using namespace std;


int	closest_to_right(int *tab, int n, int x)
{
	int	ans = n, l = 0, h = n - 1;

	while (l <= h)
	{
		int mid = l + (h - l) / 2;

		if (tab[mid] >= x)
			ans = mid,
			h = mid - 1;
		else
			l = mid + 1;
	}

	return (ans);
}

int	closest_to_left(int *tab, int n, int x)
{
	int	ans = -1, l = 0, h = n - 1;

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
	return (ans);
}


int	solve(int *arr, int n,  int l, int h)
{
	if (arr[0] > h || arr[n - 1] < l)
		return 0;
	int	left = closest_to_right(arr, n, l); 
	int	right = closest_to_left(arr, n, h); 

	return (right - left + 1);
}


int	main(void)
{
	int	n, k;
	scanf("%d", &n);
	int	arr[n];
	for (int i = 0; i < n; i++)
		scanf("%d", arr + i);
	sort(arr, arr + n);

	scanf("%d", &k);
	for (int i = 0; i < k; i++)
	{
		int l ,h;
		scanf("%d%d", &l, &h);
		printf("%d ", solve(arr, n, l, h));
	}
	cout << "\n";	
}
