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
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef pair<double, double> pdd;
typedef pair<char, int> pci;
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
#define RB rbegin()
#define E end()
#define RE rend()
#define ALL(a) a.B, a.E
#define RALL(a) a.RB, a.RE
#define nn '\n'
#define ss ' '

int case1(vi &a, vi &b) {
	return ((is_sorted(ALL(a)) && is_sorted(ALL(b))) || (is_sorted(RALL(a)) && is_sorted(RALL(b))));
}

void solve()
{
	int n; cin >> n;
	vi a(n), b(n);
	FOR (i, n) cin >> a[i];
	FOR (i, n) cin >> b[i];
	if (case1(a, b)) {
		cout << abs(a[0] - b[0]) + abs(a[n -1] - b[n-1]) << nn;
	}
	else {
		sort(ALL(a));
		sort(ALL(b));
		int ans = 0;
		FOR(i, n) {
			ans += abs(a[i] - b[i]);
		}
		cout << ans << nn;
	}
}

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
