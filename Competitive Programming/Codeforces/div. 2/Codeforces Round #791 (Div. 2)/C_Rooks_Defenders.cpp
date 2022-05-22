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
#define YESORNO(x) cout << (x? "Yes\n": "No\n")
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

struct segTree {
	typedef int T;
	static const T identity = 0;
	T fn(T a, T b) { return a + b; } // (any associative fn)
	vector<T> s; int n;
	segTree(int n = 0, T def = identity) : s(4*n, def), n(n) {}
	segTree(vector <T> &a) : s(4*a.size()), n(a.size()) {
		for (int i = 0; i < n; i++) update(i, a[i]);
	}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = fn(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int b, int e) { // query [b, e)
		T ra = identity, rb = identity;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = fn(ra, s[b++]);
			if (e % 2) rb = fn(s[--e], rb);
		}
		return fn(ra, rb);
	}
};

void solve()
{
	int m, n;
	cin >> n >> m;
	segTree cols(n, 0);
	segTree rows(n, 0);
	segTree _cols(n, 0);
	segTree _rows(n, 0);
	while (m--) {
		int q; cin>> q;
		if (q == 1 || q == 2) {
			int x, y; cin >> x >> y;
			--x, --y;
			int r = rows.query(x, x+1);
			int c = cols.query(y, y+1);
			if (q==1) r++, c++;
			else r -= !!r, c -= !!c;
			rows.update(x, r);
			cols.update(y, c);
			_rows.update(x, !!r);
			_cols.update(y, !!c);
		}
		else {
			int x, xx, y, yy;
			cin >> x >> y >> xx >> yy;
			--x, --y; --xx, --yy;
			if (x > xx) swap(x, xx);
			if (y > yy) swap(y, yy);
			YESORNO(_rows.query(x, xx+1) == xx-x+1 || _cols.query(y, yy+1) == yy-y+1);
		}
	}
}

void preprocessing() {}

bool MULTY_TEST_CASES = 0;

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
		solve();
	}
	return 0;
}