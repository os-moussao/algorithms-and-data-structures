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
	int n; cin >> n;
	multiset <int> a, b;
	for (int i = 0; i< n; i++) {
		int x; cin>> x;
		a.insert(x);
	}
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		multiset<int>::iterator it = a.find(x);
		if (it != a.end()) a.erase(it);
		else b.insert(x);
	}
	int ans = 0;
	vector <int> aa(ALL(a)), bb(ALL(b));
	for (int i: aa) {
		int log = to_string(i).length();
		if (log > 1) {
			multiset<int>::iterator it = b.find(log);
			multiset<int>::iterator it2 = a.find(i);
			if (it != b.end()) {
				b.erase(it);
				a.erase(it2);
			}
			else {
				a.erase(it2);
				a.insert(log);
			}
			ans++;
		}
	}
	for (int i: bb) {
		int log = to_string(i).length();
		if (log > 1) {
			multiset<int>::iterator it = a.find(log);
			multiset<int>::iterator it2 = b.find(i);
			if (it != a.end()) {
				a.erase(it);
				b.erase(it2);
			}
			else {
				b.erase(it2);
				b.insert(log);
			}
			ans++;
		}
	}
	for (int i: a) {
		multiset<int>::iterator it = b.find(i);
		if (it != b.end()) {
			b.erase(it);
			a.erase(a.find(i));
		}
		else if (i != 1) {
			// if ((a.find(i) == a.end()) || a.empty()) {
			// 	cerr << "ASSERT\n";
			// 	exit(1);
			// }
			// a.erase(a.find(i));
			// a.insert(1);
			ans++;
		}
	}
	for (int i: b) {
		multiset<int>::iterator it = a.find(i);
		if (it != a.end()) {
			a.erase(it);
			b.erase(b.find(i));
		}
		else if (i != 1) {
			// b.erase(b.find(i));
			// b.insert(1);
			ans++;
		}
	}
	cout << ans << endl;
	// for (int i: a) {
	// 	cerr << i << ' ';
	// }
	// cerr << endl;
	// for (int i: b) {
	// 	cerr << i << ' ';
	// }
	// cerr << endl << "-----\n";
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