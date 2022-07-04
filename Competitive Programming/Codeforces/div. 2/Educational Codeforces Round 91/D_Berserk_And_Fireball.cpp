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

using namespace std;
#define int long long
#define double long double
#define endl '\n'

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef vector<bool> vb;

#define MP(x, y) make_pair(x, y)
#define ALL(a) a.begin(), a.end()
#define RALL(a) a.rbegin(), a.rend()
#define YESORNO(x) cout << (x? "YES\n": "NO\n")
#define MAXVEC(vec) *max_element(ALL(vec))
#define MINVEC(vec) *min_element(ALL(vec))
#define getunique(vec) {sort(vec.begin(), vec.end()); vec.erase(unique(vec.begin(), vec.end()), vec.end());}
#define popcount(x) __builtin_popcountll(x);

template<class T> bool ckmin(T& a, const T b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T b) { return a < b ? a = b, 1 : 0; }
template<class T> bool ft_swap(T &mn, T &mx) {return mn > mx? (swap(mn, mx), 1): 0;}

struct segTree {
	typedef int T;
	static const T identity = 0;
	T fn(T a, T b) { return max(a, b); } // (any associative fn)
	vector<T> s; int n;
	segTree(int n = 0, T def = identity) : s(4*n, def), n(n) {}
	segTree(vector <T> &a) : s(4*a.size()), n(a.size()) {
		for (int i = 0; i < n; i++) update(i, a[i]);
	}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = fn(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int b, int e) { // query [b, e]
		T ra = identity, rb = identity; e++;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = fn(ra, s[b++]);
			if (e % 2) rb = fn(s[--e], rb);
		}
		return fn(ra, rb);
	}
};

int x, k, y;

int _solve(segTree &seg, vi &a, int l, int r) {
	int len = r-l-1;
	if (len < 0) return -1;
	int mx = seg.query(l+1, r-1);
	bool ok = l==-1? mx < a[r]: r==(int)a.size()? mx < a[l]: (mx < a[l] || mx < a[r]);
	int max_chunks = len/k;
	int mn = 1e18;
	for (int c = ok ? 0: 1; c <= max_chunks; c++) {
		ckmin(mn, x*c + y * (len - c*k));
	}
	return mn==1e18? -1: mn;
}

void solve()
{
	int n, m;
	cin >> n >> m;
	cin >> x >> k >> y;
	vi a(n), b(m);
	vi pos(n+1);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		pos[a[i]] = i;
	}
	segTree seg(a);
	for (int &i: b) cin >> i;
	int ans = 0;
	if (pos[b[0]] != 0) {
		int ret = _solve(seg, a, -1, pos[b[0]]);
		if (ret == -1) {
			cout << -1 << endl;
			return ;
		}
		ans += ret;
	}
	for (int i = 0; i+1 < m; i++) {
		int l = pos[b[i]], r = pos[b[i+1]];
		if (r-l-1 == 0) continue;
		int ret = _solve(seg, a, l, r);
		if (ret == -1) {
			cout << -1 << endl;
			return ;
		}
		ans += ret;
	}
	if (pos[b[m-1]] != n-1) {
		int ret = _solve(seg, a, pos[b[m-1]], n);
		if (ret == -1) {
			cout << -1 << endl;
			return ;
		}
		ans += ret;
	}
	cout << ans << endl;
}

void preprocessing() {}

bool MULTY_TEST_CASES = 0;

int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << setprecision(20);
	cout << fixed;

	// freopen("in", "r", stdin);
	preprocessing();

	int t = 1;
	if (MULTY_TEST_CASES) cin >> t;

	while (t--) {
		solve();
	}
}