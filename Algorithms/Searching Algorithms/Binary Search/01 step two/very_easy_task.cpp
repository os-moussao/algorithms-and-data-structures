// https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/C
#include <iostream>
#include <cmath>
using namespace std;

#define int long long

bool	valid(int a, int b, int n, int ans)
{
	return ((ans / a)+ ((ans - a) / b) >= n);
//	ans -= a;
//	n -= 1;
//	return (ans / a + ans / b >= n);
	/*
	 * this also worked but complexity will be N*logN
	for (int i = 0; i < n; i++)
		if (max(a * (n - i), b * i) == ans)
			return 1;
	return 0;
	*/
}

int32_t	main(void)
{
	int	n, a, b;
	cin >> n >> a >> b;
	
	if (a > b) swap(a, b);

	int l = 0, h = 1e18, mid, ans;

	while (l <= h)
	{
		mid = l + (h - l) / 2;
		if (valid(a, b, n, mid))
		{
			ans = mid;
			h = mid - 1;
		}
		else
			l = mid + 1;
	}

	cout << ans << "\n";
}
