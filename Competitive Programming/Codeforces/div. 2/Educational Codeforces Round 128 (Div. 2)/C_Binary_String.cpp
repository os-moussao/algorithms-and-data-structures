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
#define endl '\n'
#define YESORNO(x) cout << (x? "YES\n": "NO\n")
#define MAXVEC(vec) *max_element(ALL(vec))
#define MINVEC(vec) *min_element(ALL(vec))
#define getunique(vec)  {sort(vec.begin(), vec.end()); vec.erase(unique(vec.begin(), vec.end()), vec.end());}

template<class T> bool ckmin(T& a, const T b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T b) { return a < b ? a = b, 1 : 0; }

const int INF = 1e18L + 5;

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
}
using namespace macros;

void solve()
{
	string s;
	cin >> s;
	int lll = 0, rrr = s.L - 1;
	while (lll < s.L && s[lll] == '0') {
		lll++;
	}
	if (lll == s.L) {
		cout << '0' << endl;
		return ;
	}
	while (s[rrr] == '0') {
		rrr--;
	}

	int n = rrr-lll+1;
	s = s.substr(lll, n);

	vi pre(n);
	vi zpos;
	pre[0] = s[0] == '1';
	REP(i, 1, n) {
		pre[i] = pre[i - 1] + (s[i] == '1');
	}
	FOR (i, n) {
		if (s[i] == '0') zpos.PB(i);
	}
	if (zpos.empty()) {
		cout << 0 << endl;
		return ;
	}
	auto can = [&](int a) {
		for (int i = 0; i + a - 1 < zpos.SZ; i++) {
			int cost = 0;
			if (i+a < zpos.SZ) {
				cost += pre.back() - pre[zpos[i+a]];
			}
			if (i != 0) {
				cost += pre[zpos[i-1]];
			}
			if (cost <= a) {
				return 1;
			}
		}
		return 0;
	};

	int lo = 0, hi = zpos.SZ, mn;
	while (lo <= hi) {
		int mid = lo + (hi - lo) / 2;
		if (can(mid)) {
			hi = mid - 1;
			mn = mid;
		}
		else {
			lo = mid + 1;
		}
	}
	// for (int i = 0; i <= zpos.SZ; i++) {
	// 	cerr << can(i) << " ";
	// }
	// cerr << endl;
	cout << mn << endl;
}

void preprocessing() {}

bool MULTY_TEST_CASES = 1;

int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << setprecision(20);
	cout << fixed;

	preprocessing();

	int t = 1;
	if (MULTY_TEST_CASES) cin >> t;

	while (t--) {
		// cerr << "test #" << t << endl;
		solve();
	}
	return 0;
}