// https://cses.fi/problemset/task/1712
#include <iostream>
using namespace std;

#define nn '\n'
#define int long long
#define double long double

int	m = 1e9 + 7;

int	power(int a, int b, int mod)
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
	return res;
}

int32_t main(void)
{
	int n;
	cin >> n;

	while (n--)
	{
		int a, b, c;
		cin >> a >> b >> c;

		cout << power(a, power(b, c, m - 1), m) << nn;
	}
}
