// link: https://codeforces.com/edu/course/2/lesson/4/1/practice/contest/273169/problem/C
#include <bits/stdc++.h>

using namespace std;
#define int long long
#define double long double

struct segTree {
	typedef int T;
	static const T identity = 1e9 + 10;
	T fn(T a, T b) { return min(a, b); } // (any associative fn)
	int fnocc(int a,int b, int aa, int bb) { 
		if (a == b) return aa+bb;
		else if (a == fn(a, b)) return aa;
		else return bb;
	}
	vector<T> s, oc; int n;
	segTree(int n = 0, T def = identity) : s(4*n, def), n(n), oc(4*n, 1) {}
	segTree(vector <T> &a) : s(4*a.size()), n(a.size()) {
		for (int i = 0; i < n; i++) update(i, a[i]);
	}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;) {
			s[pos] = fn(s[pos * 2], s[pos * 2 + 1]);
			oc[pos] = fnocc(s[pos * 2], s[pos * 2 + 1], oc[2 * pos], oc[2 * pos + 1]);
		}
	}
	pair <T, int> query(int b, int e) { // query [b, e)
		T ra = identity, rb = identity;
		int ora = 0, orb = 0;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) {
				ora = fnocc(ra, s[b], ora, oc[b]);
				ra = fn(ra, s[b++]);
			}
			if (e % 2) {
				orb = fnocc(rb, s[e-1], orb, oc[e-1]);
				rb = fn(s[--e], rb);
			}
		}
		return make_pair(fn(ra, rb), fnocc(ra, rb, ora, orb));
	}
};

int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << setprecision(20);
	cout << fixed;

	int n, m;
	cin >> n >> m;
	segTree seg(n);
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		seg.update(i, x);
	}
	while (m--) {
		int q, a, b;
		cin >> q >> a >> b;
		if (q == 1) {
			seg.update(a, b);
		} else {
			pair<int , int> ans = seg.query(a, b);
			cout << ans.first << " " << ans.second << endl;
		}
	}
}