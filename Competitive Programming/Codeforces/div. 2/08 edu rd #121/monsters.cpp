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
typedef vector <pi> vpi;
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

// bool valid(int n, vpi &mon, int ans) {
// }

int sigma(int st, int en) {
	int s1 = (st * (st + 1)) / 2;
	int s2 = (en * (en + 1)) / 2;
	return s2 - s1;
}

void solve()
{
	int n;
	cin >> n;
	vpi mon(n);
	FOR (i, n) cin >> mon[i].F;
	FOR (i, n) cin >> mon[i].S;
	int ans = sigma(0, mon[0].S);
	int mom = mon[0].S;
	REP(i, 1, n) {
		int dis = mon[i].F - mon[i - 1].F;
		if (mon[i].S > dis) {
			ans += sigma(mom, mom + dis);
			mom = mom + dis;
		} else {
			ans += sigma(0, mon[i].S);
			mom = mon[i].S;
		}
	}
	cout << ans << nn;
}
/*
int lo = 0, hi = 1e18, ans, mid;
while (lo <= hi) {
	mid = lo + (hi - lo) / 2;
	if (valid(n, mon, mid)) {
		ans = mid;
		hi = mid - 1;
	} else {
		lo = mid + 1;
	}
}*/

int32_t main()
{
	int t;

	cin >> t;
	//t = 1;
	while (t--) {
		solve();
	}
	return 0;
}
