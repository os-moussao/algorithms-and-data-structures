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

bool f(char c) {
	return c=='.';
}

bool g(char c) {
	return c=='*';
}

int n, m;
vector <string> v;
int d1[8] = {1, -1, 0, 0, 1, -1, 1, -1};
int d2[8] = {0, 0, 1, -1, 1, -1, -1, 1};

bool valid(int i, int j) {
	return (i >= 0 && i < n && j >= 0 && j < m);
}

bool dfs(int i, int j, int mni, int mxi, int mnj, int mxj, int &depth) {
	v[i][j] = '.';
	depth++;
	if (((mxi-mni) > 1) || ((mxj - mnj) > 1) || (depth > 3)) {
		// cerr << i << ' ' << j << endl;
		// cerr << mxi << ' ' << mni << ' ' << mxj << ' ' << mnj << ' ' << depth << endl;
		return false;
	}
	for (int d = 0; d < 8; d++) {
		int ii = i+d1[d], jj = j+d2[d];
		if (!valid(ii,jj) || f(v[ii][jj])) continue;
		ckmin(mni, ii); ckmax(mxi, ii);
		ckmin(mnj, jj); ckmax(mxj, jj);
		if (!dfs(ii, jj, mni, mxi, mnj, mxj, depth))
			return false;
	}
	return true;
}

void solve()
{
	cin >> n >> m;
	v.resize(n);
	for (string &s: v) {
		cin>> s;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (f(v[i][j])) continue;
			int depth = 0;
			if (!dfs(i, j, i, i, j, j, depth) || (depth!=3)) {
				cout << "NO\n";
				return ;
			}
		}
	}
	cout << "YES\n";
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