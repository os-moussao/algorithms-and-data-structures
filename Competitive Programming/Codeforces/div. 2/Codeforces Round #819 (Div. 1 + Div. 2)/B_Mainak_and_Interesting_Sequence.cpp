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
	int n, m;
	cin >> n >> m;
	if (m < n) {
		cout << "No\n";
		return ;
	}
	if (n&1) {
		cout << "Yes\n";
		for (int i = 0; i< n-1; i++) {
			cout << 1 << ' ';
		}
		cout << m-(n-1) << endl;
	} else {
		if (n==2) {
			if (m%2) {
				cout << "No\n";
				return ;
			}
			else {
				cout << "Yes\n";
				cout << m/2 << ' ' << (m+1)/2 << endl;
			}
		}
		else {
			if (m%n == 0) {
				cout << "YES\n";
				for (int i = 0; i< n; i++) {
					cout << m/n << ' ';
				}
				cout << endl;
			}
			else {
				if (m&1) {
					cout << "No\n";
				} else {
					cout << "Yes\n";
					for (int i = 0; i < n-2; i++) {
						cout << "1 ";
					}
					m=m-(n-2);
					cout << m/2 << ' ' << m/2 << endl;
				}
			}
		}
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