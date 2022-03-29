#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

#define int long long
#define double long double

#define REP(i, n) for(int i = 0; i < n; i++)
#define nn '\n'
#define ss ' '

const int MOD = 1e9 + 7;

void solve()
{
	int a, b;
	cin >> a >> b;

	while (a && b)
	{
		if (a % 10 + b % 10 >= 10)
		{
			cout << "Hard" << nn;
			return ;
		}
		a /= 10;
		b /= 10;
	}
	cout << "Easy" << nn;
}

int32_t main()
{
	int t;

	t = 1;
	while (t--) {
		solve();
	}
	return 0;
}
