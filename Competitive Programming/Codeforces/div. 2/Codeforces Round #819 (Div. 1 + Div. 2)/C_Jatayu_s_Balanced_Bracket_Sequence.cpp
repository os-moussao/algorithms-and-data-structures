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

#ifdef LOCAL
#include "debug.hpp"
#else
#define debug(x...)
#endif

class DSU {
	public:
		int n;
		vector <int> par;
		vector <int> sz;
		int cnt;
		DSU(){}
		DSU(int N) {
			n = cnt = N;
			par.resize(n); sz.resize(n);
			while (N--) {
				par[N] = N;
				sz[N] = 1;
			}
		}
		int find(int p) {
			return par[p] == p? p: par[p] = find(par[p]);
		}
		bool connected(int p, int q) {
			return find(p) == find(q);
		}
		int size(int p) {
			return sz[find(p)];
		}
		bool join(int p, int q) {
			int root1 = find(p);
			int root2 = find(q);
			if (root1 == root2) return 0;
			if (sz[root1] < sz[root2]) swap(root1, root2);
			par[root2] = root1;
			sz[root1] += sz[root2];
			cnt--;
			return 1;
		}
};

struct segTree {
	typedef int T;
	static const T identity = (int)1e9;
	T fn(T a, T b) { return min(a, b); } // (any associative fn)
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

void solve()
{
	int n; cin >> n; string s; cin >> s;
	vector <int> pre(s.length()+1);
	vector <vector <int>> pos(n+1);
	pos[0].push_back(0);
	for (int i = 1; i <= s.length(); i++) {
		pre[i] = pre[i-1] + (s[i-1] == '('? 1: -1);
		pos[pre[i]].push_back(i);
	}
	segTree seg(pre);
	DSU dsu(s.length()+1);
	for (int i = 1; i < pos[0].size(); i++) {
		dsu.join(pos[0][i-1]+1, pos[0][i]);
		dsu.join(pos[0][i-1], pos[0][i]);
	}
	for (int j = 1; j < n+1; j++) {
		for (int i = 1; i < pos[j].size(); i++) {
			int x = pos[j][i-1], y = pos[j][i];
			// make edge from x+1 and y ?
			if (((x+2) - (y-1) == 0) || (seg.query(x+2,y-1) >= pre[y])) {
				dsu.join(x+1, y);
			}
			// make edge from x and y ?
			// if ((i >= 2 && dsu.connected(x, pos[j][i-2]+1))) {
			// 	dsu.join(x, y);
			// }
		}
	}
	cout << dsu.cnt - (dsu.size(0) == 1) << endl;
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
		solve();
	}
}