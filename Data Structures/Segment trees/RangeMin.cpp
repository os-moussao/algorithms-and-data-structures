// link: https://cses.fi/problemset/task/1649
#include <bits/stdc++.h>

using namespace std;
#define int long long
#define endl '\n'

struct segTree {
	typedef int T;
	static const T identity = 1e18;
	T fn(T a, T b) { return min(a, b); } // (any associative fn)
	vector<T> s; int n;
	segTree(int n = 0, T def = identity) : s(4*n, def), n(n) {}
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

// Dynamic Range Minimum Queries
int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	segTree st(n);
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		st.update(i, x);
	}
	while (m--) {
		int q, a, b;
		cin >> q >> a >> b;
		if (q == 1) {
			st.update(--a, b);
		}
		else {
			cout << st.query(--a, b) << endl;
		}
	}
}