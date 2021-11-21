// https://cses.fi/problemset/task/1712
#include <iostream>
using namespace std;

#define nn '\n'
#define int long long
#define double long double

int	m = 1e9 + 7;

int	power(int a, int b, int mod)
{
	if (b == 0)
		return 1;
	a %= mod;
	int res = 1;
	while (b > 0)
	{
		if (b % 2)
		{
			res = (res * a) % mod;
			b--;
		}
		else
		{
			a = (a * a) % mod;
			b /= 2;
		}
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
