// cses: https://cses.fi/problemset/task/1633/

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
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
#define MP(x, y) make_pair(x, y)
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
#define YESORNO(x) cout << (x? "YES\n": "NO\n")

const int MOD = 1e9 + 7;

// int sol(int n) {
// 	vi dp = {1, 2, 4};
// 	if (n <= 0) return 0;
// 	if (n <= 3) {
// 		return dp[n - 1];
// 	}
// 	return (n <= 6) + sol(n - 1) + sol(n - 2) + sol(n - 3) + sol(n - 4) + sol(n - 5) + sol(n - 6);
// }

void solve()
{
	int n; cin >> n;
	vi dp {
		0, 0 ,0, 1, 2, 4
	};
	if (n <= 3) {
		cout << dp[2 + n] << nn;
		return ;
	}
	FOR(i, n - 3) {
		int sum = 0;
		FOR (i, 5) {
			sum += dp[i];
			dp[i] = dp[i + 1];
		}
		dp[5] += sum + ((i + 4) <= 6);
		dp[5] %= MOD;
	}
	cout << dp[5] << nn;
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
