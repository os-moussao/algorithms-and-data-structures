// https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/A
#include <iostream>
#include <cmath>
using namespace std;

long long	solve(long long w, long long h, long long n)
{
	long long l = 0, r = 1, mid, valid;

	while (!((floor(r/h) * floor(r/w)) >= n))
		r *= 2;

	while (r > l + 1)
	{
		mid = l + (r - l) / 2;
		if ((floor(mid/h) * floor(mid/w)) >= n)
			r = mid;
		else
			l = mid;
	}
	return (r);
}

int	main(void)
{
	long long	w, h, n;
	cin >> w >> h >> n;
	cout << solve(w, h, n) << endl;
}
