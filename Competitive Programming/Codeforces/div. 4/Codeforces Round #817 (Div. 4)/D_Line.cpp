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

void solve()
{
	int n; string s;
	cin >> n;
	cin >> s;
	vector <int> opt (n+1), a(n), b(n), pre(n+1);
	for (int i = 1; i <= n; i++) {
		if (s[i-1]=='L') {
			b[i-1] = i-1;
		} else {
			b[i-1] = n-i;
		}
	}
	for (int i = 0; i < n; i++) {
		if (i < n/2) {
			a[i] = n-i-1;
		} else {
			a[i] = i;
		}
	}
	vector <int> c(n);
	for (int i = 0; i < n; i++) {
		c[i] = a[i]-b[i];
	}
	sort(RALL(c));
	for (int i = 1; i <= n; i++) {
		opt[i] = c[i-1]+opt[i-1];
	}
	for (int i = 1; i <= n; i++) {
		pre[i] = b[i-1]+pre[i-1];
	}
	// for (int i: a) {
	// 	cerr << i << ' ';
	// }
	// cerr << endl;
	// for (int i : b) {
	// 	cerr << i << ' ';
	// }
	// cerr << endl;
	// for (int i : c) {
	// 	cerr << i << ' ';
	// }
	// cerr << endl;
	// for (int i: opt) {
	// 	cerr << i << ' ';
	// }
	// cerr << endl;
	// for (int i : pre) {
	// 	cerr << i << ' ';
	// }
	for (int i = 1; i <= n; i++) {
		cout << opt[i] + pre[n] << ' ';
	}
	cout << endl;
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