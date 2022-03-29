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

bool valid(int *a, int n, int l, int r, int k, int ans)
{
	int bars = 0, price = 0;

	REP(i, n)
	{
		if (a[i] < l)
			continue ;
		if (a[i] > r)
			break ;
		if (price + a[i] > k)
			break ;
		price += a[i];
		bars++;
	}
	return (ans <= bars);
}

void solve()
{
	int n, l, r, k;
	cin >> n >> l >> r >> k;

	int a[n];
	REP(i, n) cin >> a[i];


	sort(a, a + n);
	
	int bars = 0, price = 0;

	REP(i, n)
	{
		if (a[i] < l)
			continue ;
		if (a[i] > r)
			break ;
		if (price + a[i] > k)
			break ;
		price += a[i];
		bars++;
	}
	cout << bars << nn;


	/*
	int lo = 0, hi = n, mid;
	while (hi > lo + 1)
	{
		if (valid(a, n, l, r, k, mid))
			lo = mid;
		else
			hi = mid;
	}
	cout << lo << nn;
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
