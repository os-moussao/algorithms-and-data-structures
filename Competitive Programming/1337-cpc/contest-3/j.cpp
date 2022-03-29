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
#define MAXVEC(vec) *max_element(ALL(vec))
#define MINVEC(vec) *min_element(ALL(vec))

const int mod = 998244353;

int values[1000005][11];
int n;

int solve(int i, int d) {
	if (d < 1 || d > 9)
		return values[i][d] = 0;
	if (i == n - 1)
		return values[i][d] = 1;

	if (values[i][d] != -1) return values[i][d];
	
	int ans = 0;
	ans = solve(i + 1, d - 1) + solve(i + 1, d) + solve(i + 1, d + 1);
	ans %= mod;

	return values[i][d] = ans;
}

int32_t main()
{
	cin >> n;
	memset(values, -1, sizeof values);
	int ans = 0;
	REP(i, 1, 10) {
		ans += solve(0, i);
		ans %= mod;
	}
	cout << ans << nn;

	return 0;
}
