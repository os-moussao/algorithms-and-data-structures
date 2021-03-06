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

// this function will segfault (cause a stack overflow) if the numbers are too high
// O(3^n) too high
bool valid(int a, int b, int t)
{
	if (a < 0 || b < 0)
		return 0;

	if (t == 0)
		return 1;

	return valid(a - 2, b - 2, t - 1) ||
		valid(a - 1, b - 3, t - 1) || valid(a - 3, b - 1, t - 1);
}

void solve()
{
	int a, b;
	cin >> a >> b;

	if (a < b) swap(a, b);
	int k = min({a/3, b, (a-b)/2});  /*min((a - b) / 2, min(a / 3, b)) */ 
	/*
	while (a < 3*k || b < k && k >= 0)
		k--;
	*/
	a -= 3*k; b -= k;
	cout << min(a, b) / 2 + k << nn;
	/*
	int lo = 0, hi = min(a, b), mid, ans;

	while (hi >= lo)
	{
		mid = lo + (hi - lo) / 2;
		if (valid(a, b, mid))
		{
			ans = mid;
			lo = mid + 1;
		}
		else
			hi = mid - 1;
	}
	cout << ans << nn;
	*/
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
