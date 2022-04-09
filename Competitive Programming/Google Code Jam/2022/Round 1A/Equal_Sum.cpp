#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
#include <algorithm>

namespace macros {

using namespace std;

#define int long long
#define double long double

typedef vector<bool> vb;
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
#define getunique(vec)  {sort(vec.begin(), vec.end()); vec.erase(unique(vec.begin(), vec.end()), vec.end());}

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

} using namespace macros;
int	power(int a, int b);
int	mpower(int a, int b, int mod);
void    setIO(string s);


void solve()
{
	int n;
	cin >> n;

	if (n == -1) {
		exit(1);
	}

	int sum = 0;
	vi a(2 * n);
	int nbr = 1;
	int exp = 0;
	FOR (i, n) {
		if (exp < 29) {
			a[i] = nbr;
			nbr <<= 1;
			exp++;
		}
		else
			a[i] = ++nbr;
		sum += a[i];
		cout << a[i];
		if (i != n -1) cout << ss;
	}
	cout << nn<<flush;
	REP (i, n,  2*n) {
		cin >> a[i];
		sum += a[i];
	}
	sum /= 2;
	sort(ALL(a));

	vi ans;
	int i = 2 * n - 1;
	while (sum && i >= 0) {
		if (sum - a[i] < 0) {i--; continue ;}
		ans.PB(a[i]);
		sum -= a[i];
		i--;
	}

	FOR (j, (int)(ans.SZ)) {
		cout << ans[j];
		if (j != (int)(ans.SZ- 1)) cout << ss;
	}
	cout << nn<<flush;
}

void preprocessing() {}

bool MULTY_TEST_CASES = 1;

int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << setprecision(20);
	cout << fixed;
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
	// setIO("");

	preprocessing();

	int t = 1;
	if (MULTY_TEST_CASES) cin >> t;

	for (int i = 1; i <= t; i++) {
		// cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int	power(int a, int b)
{
	int res = 1;
	while (b > 0)
	{
		if (b & 1)
			res *= a;
		a *= a;
		b >>= 1;
	}
	return res;
}

int	mpower(int a, int b, int mod)
{
	a %= mod;
	int res = 1;
	while (b > 0)
	{
		if (b & 1)
			res = (res * a) % mod;
		a = (a * a) % mod;
		b >>= 1;
	}
	return res;
}
