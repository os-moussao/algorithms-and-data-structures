#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cstdint>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <deque>

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
#ifndef LOCAL
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
} using namespace macros;
void    setIO(string s);


struct range {
	int p;
	int sp;
	int s;
	int e;
};

void solve()
{
	int n;
	cin >> n;
	vi a(n);
	FOR(i, n) {
		cin >> a[i];
	}
	vector <range> rg;
	int s = 0, e = 0, p = 0, sp = 1;
	FOR (i, n + 1) {
		if (i == n || a[i] == 0) {
			rg.PB({p, sp, s, i});
			if (i == n) break ;
			while (i < a.SZ && a[i] == 0) i++;
			s = i--;
			p = 0;
			sp = 1;
			continue;
		}
		p += abs(a[i]) == 2;
		sp *= a[i] / abs(a[i]);
	}
	int mx = -1;
	int l = 0, ri = 0;
	for (range &r: rg) {
		if (r.sp < 0) {
			int p1 = 0, p2 = 0;
			int j1 = r.s, j2 = r.e - 1;
			while (j1 < r.e && a[j1] > 0)
			{
				p1 += a[j1] == 2;
				j1++;
			}
			p1 += a[j1] == -2;
			j1++;
			while (j2 >= r.s && a[j2] > 0)
			{
				p2 += a[j2] == 2;
				j2--;
			}
			p2 += a[j2] == -2;
			j2--;
			if (p1 < p2) {
				r.p -= p1;
				r.s = j1;
			}
			else {
				r.p -= p2;
				r.e = j2 + 1;
			}
		}
		if (r.p > mx) {
			mx = r.p;
			l = r.s;
			ri = n - r.e;
		}
	}
	cout << l << ss << ri << nn;
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

	while (t--) {
		solve();
	}
	return 0;
}

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}
