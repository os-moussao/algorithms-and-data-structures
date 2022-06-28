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
	int n; cin >> n;
	int z = 0, zi=  -1;
	vi a(n);
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		a[i] = x;
	}
	int s = 0, e = n-1;
	while (s < n && a[s] == 0) {
		s++;
	}
	while (e >= s && a[e] == 0) {
		e--;
	}
	for (int i = s; i <= e; i++) {
		if (!a[i]) z++, zi = i;
	}
	int len = (e-s+1);
	// cerr << s << " " << e << " " << len << endl;
	for (int i = s; i <= e; i++) {
		if (!a[i]) {
			z++;
			zi = i;
		}
	}
	if (!len) {
		cout << 0 << endl;
	}
	else if (z == 0) {
		cout << 1 << endl;
	}
	else if (z == 1 && (zi == s || zi == e)){
		cout << 1 << endl;
	}
	else {
		cout << 2 << endl;
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