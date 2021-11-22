// https://codeforces.com/gym/102644/problem/A
#include <iostream>
#include <iomanip>

using namespace std;

#define int long long
#define double long double
#define nn '\n'
#define ss ' '

double solve(int n, double p);
double solve_me(int n, double p);

int32_t main()
{
	int n;
	double p;
	cin >> n >> p;

	cout << fixed << setprecision(10) << solve(n, p) << nn;
	return 0;
}

/* errichto's way in O(log(n)) */
double solve(int n, double p)
{
	double ans = 1.0;

	while (n > 0)
	{
		if (n % 2 == 1)
			ans = ans * (1 - p) + (1 - ans) * p;
		p = 2 * p * (1 - p);
		n /= 2;
	}
	return (ans);
}

/* how I tried to solve this problem, in O(n)
 * time limit exceeded in test 30
 **/
double solve_me(int n, double p)
{
	double happy = 1.000, sad = 0.000;

	if (n % 2 == 1)
	{
		happy *= (1 - p);
		sad = 1 - happy;
		n--;
	}
	while (n > 1)
	{
		happy = happy * ((1-p)*(1-p) + p*p) + sad * 2 * (1-p) * p;
		sad = 1 - happy;
		n -= 2;
	}
	return (happy);
}
