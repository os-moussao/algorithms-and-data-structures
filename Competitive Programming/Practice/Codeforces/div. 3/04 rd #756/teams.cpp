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

bool valid(int a, int b, int t)
{
	if (a < 0 || b < 0)
		return false;
	if (t == 0)
		return true;
	if (valid(a - 2, b - 2, t - 1))
		return true;
	else
		return valid(max(a, b) - 3, min(a, b) - 1, t - 1);
}

void solve()
{
	int a, b;
	cin >> a >> b;

	if (a > b) swap(a, b);

	int lo = 0, hi = min(a, b), mid;

	while (hi > lo + 1)
	{
		mid = lo + (hi - lo) / 2;
		if (valid(a, b, mid))
			lo = mid;
		else
			hi = mid;
	}
	cout << lo << nn;
}

int32_t main()
{
	int t;

	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
