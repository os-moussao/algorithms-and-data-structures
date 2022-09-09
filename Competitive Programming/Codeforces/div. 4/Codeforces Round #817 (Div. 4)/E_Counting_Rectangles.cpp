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
template<class T> bool ft_swap(T &mn, T &mx) { return mn > mx? (swap(mn, mx), 1): 0; }

void solve()
{
	int n, q;
	cin >> n >> q;
	vector <pair<int, int>> rec(n);
	vector<vector <int>> sum(1001, vector <int> (1001));
	// int mx_x = 10, mx_y = 10;
	for (pi &p: rec) {
		cin >> p.first >> p.second;
		sum[p.first][p.second] += p.first*p.second;
	}

	// for (int i = 0; i <= mx_x; i++) {
	// 	for (int j = 0; j <= mx_y; j++) {
	// 		cerr << sum[i][j] << ' ';
	// 	}
	// 	cerr << endl;
	// }
	// cerr << endl;

	for (int i = 1; i <= 1000; i++) {
		for (int j = 1; j <= 1000; j++) {
			sum[i][j] += sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
		}
	}

	// for (int i = 0; i <= mx_x; i++) {
	// 	for (int j = 0; j <= mx_y; j++) {
	// 		cerr << sum[i][j] << ' ';
	// 	}
	// 	cerr << endl;
	// }


	while(q--) {
		int x, y, xx, yy;
		cin >> x >> y >> xx >> yy;
		// xx-1 yy-1    x y
		cout << sum[xx-1][yy-1] - (sum[x][yy-1] + sum[xx-1][y] - sum[x][y]) << endl;
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