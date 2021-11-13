// https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/B
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

bool	valid(int *ropes, int n, int k, double x)
{
	long long	res = 0;
	for (int i = 0; i < n; i++)
		res += floor((long long)ropes[i] / x);
	return (res >= (long long)k);
}

double	solve(int *ropes, int n, int k)
{
	double l = 0, h = 1e8, mid, eps = 1e-6;

	// l, h <= 1e9
	// --> l*h <= 1e18
	// log2(1e18) --> 60
	
	cout << setprecision(20);
	for (int i = 0; i < 100; i++)
//	while (h - l > eps)
	{
		mid = l + (h - l) / 2;
		if (valid(ropes, n, k, mid))
			l = mid;
		else
			h = mid;
//		cout << "it = " << i << " low = " << l << " hight = " << h << '\n';
	}
	return (l);
}

int	main(void)
{
	int	n, k;
	cin >> n >> k;

	int	ropes[n];
	for (int i = 0; i < n; i++)
		cin >> ropes[i];

//	cout << setprecision(20);
	cout << solve(ropes, n, k) << '\n';
}
