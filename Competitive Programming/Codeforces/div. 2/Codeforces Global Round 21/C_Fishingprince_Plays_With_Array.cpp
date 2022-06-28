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

int	power(int a, int b)
{
	int res = 1;
	while (b > 0)
	{
		if (b & 1)
			res = (res * a);
		a = (a * a);
		b >>= 1;
	}
	return res;
}

vpi get(vi &a, int m) {
	vpi res;
	for (int i = 0; i < a.size(); i++) {
		int x = a[i], t = 0;
		// O(log a[i])
		while (x % m == 0) {
			t++;
			x /= m;
		}
		if (!res.empty() && res.back().first == x) {
			res.back().second += power(m, t);
		}
		else {
			res.push_back({x, power(m, t)});
		}
	}
	return res;
}

void solve()
{
	int n, m;
	cin >> n >> m;
	vi a(n);
	for (int &i : a) cin >> i;
	int k; cin >> k;
	vi b(k);
	for (int &i: b) cin >> i;
	vpi aa = get(a, m);
	// for (int i = 0; i < aa.size(); i++) {
	// 	cout << aa[i].first << " " << aa[i].second << endl;
	// }
	for (int i = k-1; i >= 0; i--) {
		int x = b[i], t = 0;
		while (x % m == 0) {
			x /= m;
			t++;
		}
		t = power(m, t);
		while (t) {
			if (aa.empty() || aa.back().first != x) {
				cout << "No" << endl;
				return ;
			}
			int have = aa.back().second;
			int get = min(t, have);
			t -= get;
			aa.back().second -= get;
			if (!aa.back().second) {
				aa.pop_back();
			}
		}
	}
	cout << (aa.empty() ? "Yes": "No") << endl;
}

void preprocessing() {}

bool MULTY_TEST_CASES = 1;

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