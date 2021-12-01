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

bool valid(int *arr, int n, int h, int k)
{
	int c = 0;

	REP(i, n)
	{
	
		if (i < n - 1)
			c += min(k, arr[i + 1] - arr[i]);
		else
			c += k;
	if (c >= h)
			return (1);
	}
	return (0);
}

void solve()
{
	int n, h;
	cin >> n >> h;

	int arr[n];
	REP(i, n) cin >> arr[i];

	int lo = 0, hi = 1e18, k, mid;
	while (hi >= lo){
		mid = lo + (hi - lo) / 2;
		if (valid(arr, n, h, mid))
		{
			hi = mid - 1;
			k = mid;
		}
		else
			lo = mid + 1;
	}
	cout << k << nn;
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
