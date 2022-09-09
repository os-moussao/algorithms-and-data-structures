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

bool MULTY_TEST_CASES = 1;

int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << setprecision(20);
	cout << fixed;

	int n, d; cin >> n >> d;
	vector <int> a(n);
	for (int &i: a) cin >> i;
	sort(ALL(a));
	int ans = 0;
	int sz = 0;
	debug(a);
	for (int i = n-1; i >= 0; i--) {
		int x = a[i];
		if (x > d && (sz+1) <= n) {
			sz++;
			ans++;
		} else if (x <= d) {
			int diff = d-x;
			if (!diff && (sz+2) <= n) {
				sz+=2;
				ans++;
			} else if (diff) {
				// int need = (diff+x-1)/x;
				int need = ceil((double)diff/(double)x);
				if ((need+1) * x <= d) {
					need++;
				}
				debug(i, x, diff, need);
				if (sz+1+need <= n) {
					sz += need+1;
					ans++;
				}
			}
		}
		debug(x, sz, ans);
	}
	cout << ans << endl;
}