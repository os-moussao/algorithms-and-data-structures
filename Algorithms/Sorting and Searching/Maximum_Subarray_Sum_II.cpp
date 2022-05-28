// task: https://cses.fi/problemset/task/1644
#include <bits/stc++.h>

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

template<class T> bool ckmin(T& a, const T b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T b) { return a < b ? a = b, 1 : 0; }
template<class T> bool ft_swap(T &mn, T &mx) {return mn > mx? (swap(mn, mx), 1): 0;}

struct segTree {
	typedef int T;
	static const T identity = -1e18;
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
	T query(int b, int e) { // query [b, e)
		T ra = identity, rb = identity;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = fn(ra, s[b++]);
			if (e % 2) rb = fn(s[--e], rb);
		}
		return fn(ra, rb);
	}
};

int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << setprecision(20);
	int n, a, b;
	cin >> n >> a >> b;
	vi arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	vi pre(n+1); pre[0] = 0;
	for (int i = 1; i <= n; i++) pre[i] = pre[i-1] + arr[i-1];
	// for (int i = 0; i <= n; i++) cerr << pre[i]  << " ";
	// cerr << endl;
	segTree seg(pre);
	int mx = -1e18;
	for (int i = 0; i + a <= n; i++) {
		int l = i+a, r = min(i+b, n);
		int opt = seg.query(l, r+1);
		// cerr << "max between " << l << " and " << r << ": " << opt << endl;
		ckmax(mx, opt-pre[i]);
	}
	cout << mx << endl;
}