#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>
#include <limits.h>

using namespace std;

#define int long long
#define double long double

#define REP(i, n) for(int i = 0; i < n; i++)
#define nn '\n'
#define ss ' '

void solve()
{
	int n;
	cin >> n;

	int arr[n];
	REP(i, n) cin >> arr[i];
	
	int k = 1;
	int s = 0;
	int m = -1;
	int in = -1;
	REP(i, n)
	{
		while (!(arr[i]&1))
		{
			arr[i] >>= 1;
			k <<= 1;
		}
		if (arr[i] > m)
		{
			m = arr[i];
			in = i;
		}
		s += arr[i];
	}
	cout << s - arr[in] + arr[in] * k << nn;
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
