#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <cmath>

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

int sums2d(pii s, pii e, vvi &sums)
{
	return (sums[e.F][e.S] - sums[s.F - 1][e.S] - sums[e.F][s.S - 1]
		   	+ sums[s.F - 1][s.S - 1]);
}

void solve()
{
	int n , m, q;
	cin >> n >> m >> q;

	vvi Bridge(n + 1, vi(m + 1, 0));
	REP(i, 1, n + 1)
	{
		REP(j, 1, m + 1)
		{
		char c;
		cin >> c;
	Bridge[i][j] = Bridge[i][j - 1] + Bridge[i - 1][j] - Bridge[i - 1][j - 1] + (c == 'r');
		}
	}

	FOR(i, q)
	{
		pi s, e;
		cin >> s.F >> s.S >> e.F >> e.S;
		cout << sums2d(s, e, Bridge) << nn;
	}
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
