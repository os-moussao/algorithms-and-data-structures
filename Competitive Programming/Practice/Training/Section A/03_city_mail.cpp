// https://codeforces.com/contest/567/problem/A
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;

#define int long long
#define double long double

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<char, int> pci;
typedef vector<pii> vpii;
typedef vector<pdd> vpdd;
typedef vector<pci> vpci;

#define REP(i, a, n) for(int i = a; i < n; i++)
#define FOR(i, n) for(int i = 0; i < n; i++)
#define RREP(i, n, a) for(int i = n; i >= a; i--)
#define RFOR(i, n) for(int i = n; i >= 0; i--)
#define ITER(i, a, b) for(auto i = a; i != b; i++)
#define SZ size()
#define L length()
#define F first
#define S second
#define PB push_back
#define PF push_front
#define B begin()
#define E end()
#define nn '\n'
#define ss ' '

void solve()
{
	int n; cin >> n;
	vpi arr(n);
	FOR(i, n)
	{
		cin >> arr[i].F;
		arr[i].S = i;
	}
	sort(arr.B, arr.E);
	vpi ans(n);
	FOR(i, n)
	{
		int mi, ma;
		if (i == 0)
			mi = arr[i + 1].F - arr[i].F, ma = arr[n - 1].F - arr[i].F;
		else if (i == n - 1)
			mi = arr[i].F - arr[i - 1].F, ma = arr[i].F - arr[0].F;
		else
		{
			mi = min(arr[i].F - arr[i - 1].F, arr[i + 1].F - arr[i].F);
			ma = max(arr[n-1].F - arr[i].F, arr[i].F - arr[0].F);
		}
		ans[arr[i].S].F = mi;
		ans[arr[i].S].S = ma;
	}
	FOR(i, n)
		cout << ans[i].F << ss << ans[i].S << nn;
}

int32_t main()
{
	int t;

	//cin >> t;
	t = 1;
	while (t--) {
		solve();
	}
	return 0;
}
