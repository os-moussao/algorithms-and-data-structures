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
	int n, w;
	cin >> n >> w;

	vector<pair<int,int>> a(n);
	REP(i, n) { int x, y; cin >> x >> y; a[i] = {x,y}; }

int ans = 0;
sort(a.begin(), a.end(), [&](pair<int,int> i, pair<int,int> j){return i.first > j.first;});

	REP(i, n)
	{
		if (w >= a[i].second)
		{
			ans += a[i].first * a[i].second;
			w -= a[i].second;
		} 
		else
		{
			ans += a[i].first * w;
			break ;
		}
	}
	cout << ans << nn;
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
