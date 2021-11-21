#include <iostream>
#include <iomanip>

using namespace std;

#define int long long
#define double long double
#define nn '\n'
#define ss ' '

double solve_err(int n, double p)
{
	double ans = 1.0;

	while (n > 0)
	{
		if (n % 2 == 1)
		{
			ans = ans * (1 - p) + (1 - ans) * p;
		}
		p *= 2 * (1 - p);
		n /= 2;
	}
	return (ans);
}

double solve_me(int n, double p)
{
	double ans = 1.0;

	if (n % 2 == 1)
	{
		ans *= (1 - p);
		if (--n)
		{
			ans = ans * ((1 - p)*(1 - p) + p*p) + 2 * p * (1 - p) * (1 - ans);
			n /= 2;
		}
	}
	while (n > 1)
	{
		ans *= ((1 - p)*(1 - p) + p*p);
		n /= 2;
	}
	return (ans);
}

int32_t main()
{
	cout << setprecision(10);
	int n;
	double p;
	cin >> n >> p;

	cout << fixed << setprecision(10) << solve_err(n, p) << nn;
	cout << fixed << setprecision(10) << solve_me(n, p) << nn;
	return 0;
}
