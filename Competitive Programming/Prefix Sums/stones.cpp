// https://codeforces.com/contest/433/problem/B
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

#define int long long
#define double long double

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;

#define REP(i, a, n) for(int i = a; i < n; i++)
#define SZ size()
#define LN length()
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
	int n;
	cin >> n;

	vi v(n);
	vi sv(n + 1); sv[0] = 0;
	REP(i, 0, n) cin >> v[i];

	vi u = v;
	vi su(n + 1); su[0] = 0;
	sort(u.B, u.E);

	REP(i, 1, n + 1) sv[i] = sv[i - 1] + v[i - 1];

	REP(i, 1, n + 1) su[i] = su[i - 1] + u[i - 1];
	
	int m;
	cin >> m;

	REP(i, 0, m)
	{
		int q, l, r;
		cin >> q >> l >> r;

		if (q == 1)
			cout << sv[r] - sv[l - 1] << nn;
		else
			cout << su[r] - su[l - 1] << nn;
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
