// task: https://cses.fi/problemset/task/1095/
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define double long double

int	mod = 1e9 + 7;

int	power(int a, int b)
{
	a %= mod;
	int res = 1;
	while (b > 0)
	{
		if (b & 1)
			res = (res * a) % mod;
		a = (a * a) % mod;
		b >>= 1;
	}
	return (res % mod);
}

int32_t main(void)
{
	int n;
	cin >> n;

	while (n--)
	{
		int a, b;
		cin >> a >> b;

		cout << power(a, b) << "\n";
	}
}
