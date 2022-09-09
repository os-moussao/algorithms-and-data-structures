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

void solve()
{
	int n, k, r, c;
	cin >> n >> k >> r >> c; --r, --c;
	vector <string> v(n, string(n,'.'));
	v[r][c] = 'X';
	vector <string> vv = v;
	for (int i = r; i < n; i++) {
		if (c-abs(i-r) >= 0) v[i][c-abs(i-r)] = 'X';
		for (int j = 0; j < n; j++) {
			// cerr << abs(j-(c-abs(i-r))) << endl;
			if (( abs( j - (c-abs(i-r)) ) % (k)) == 0)
				v[i][j] = 'X';
		}
	}
	for (int i = r; i >= 0; i--) {
		if (c+abs(i-r) < n) v[i][c+abs(i-r)] = 'X';
		for (int j = 0; j < n; j++) {
			// cerr << abs(j- (c-abs(i-r)) ) << endl;
			if ((abs(j-(c+abs(i-r))) % (k)) == 0)
				v[i][j] = 'X';
		}
	}
	
	for (int i = r; i < n; i++) {
		if (c+abs(i-r) < n) vv[i][c+abs(i-r)] = 'X';
		for (int j = 0; j < n; j++) {
			// cerr << abs(j-(c-abs(i-r))) << endl;
			if (( abs( j - (c+abs(i-r)) ) % (k)) == 0)
				vv[i][j] = 'X';
		}
	}
	for (int i = r; i >= 0; i--) {
		if (c-abs(i-r) >= 0) vv[i][c-abs(i-r)] = 'X';
		for (int j = 0; j < n; j++) {
			// cerr << abs(j- (c-abs(i-r)) ) << endl;
			if ((abs(j-(c-abs(i-r))) % (k)) == 0)
				vv[i][j] = 'X';
		}
	}

	int a = 0, b = 0;
	for (string &s: v) {
		a += count(ALL(s), 'X');
	}
	for (string &s: vv) {
		// cerr << s << endl;
		b += count(ALL(s), 'X');
	}
	if (a <= b) {
		for (string &s: v) cout << s << endl;
	} else {
		for (string &s: vv) cout << s << endl;
	}
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