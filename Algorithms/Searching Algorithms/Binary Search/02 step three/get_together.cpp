// https://codeforces.com/edu/course/2/lesson/6/3/practice/contest/285083/problem/A
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

#define int long long
#define double long double

struct pt{
	int x;
	int v;
};

bool	valid(pt *arr, double t, int n)
{
	double left = (arr[0].x - t * arr[0].v), right = (arr[0].x + t * arr[0].v);
	for (int i = 1;i < n; i++)
	{
		double l =  (arr[i].x - t * arr[i].v), r = (arr[i].x + t * arr[i].v);
		if (l > left)
			left = l;
		if (r < right)
			right = r;
	}
	return (right - left > 1e-6);
}

int32_t	main(void)
{
	int	n;
	cin >> n;

	pt	arr[n];
	for (int i = 0; i< n; i++)
		cin >> arr[i].x >> arr[i].v;

	double lo = 0, hi = (int)1e17, t, eps = 1e-6;

	for (int i = 0; i < 100; i++)
	// while (hi - lo > eps)
	{
		t = lo + (hi - lo) / 2;
		if (valid(arr, t, n))
			hi = t;
		else
			lo = t;
	}

	cout <<fixed << setprecision(6) << hi << "\n";
}
