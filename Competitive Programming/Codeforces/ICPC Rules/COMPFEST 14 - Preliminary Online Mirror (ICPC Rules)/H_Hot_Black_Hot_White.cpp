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

int mult3(int x, int y) {
	x %= 3, y %= 3;
	ft_swap(x, y);
	if (!x) return 0;
	else if (x==1) return y;
	else return 1;
}

int concat(int &x, int &y) {
	return (x%3+y%3)%3;
};

bool dangerous(int x, int y, int z) {
	int vl = concat(x,y);
	return ((vl*vl)%3+mult3(x,y))%3==z;
}

int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << setprecision(20);
	cout << fixed;

	// vector <int> s1 = {4, 9}, s2 = {10, 14};
	// for (int i: s1) {
	// 	for (int j: s2) {
	// 		cerr << dangerous(i, j, 0) << ' ';
	// 	}
	// 	cerr << endl;
	// }

	int n; cin >> n;
	vector <int> a(n);
	for (int &i: a) cin>> i, i %= 3;
	// debug(a);
	for (int z = 0; z < 3; z++) {
		set<int> s1, s2;
		for (int a = 0; a < 3; a++) {
			for (int b = 0; b < 3; b++) {
				if (dangerous(a, b, z)) {
					s1.insert(a); s1.insert(b);
				}
			}
		}
		for (int a = 0; a < 3; a++) {
			if (s1.find(a) == s1.end()) {
				s2.insert(a);
			}
		}
		string ans(n, '0');
		int sz = 0;
		for (int i = 0; i < n; i++) {
			if (s1.find(a[i]) != s1.end()) {
				ans[i] = '1';
				sz++;
			}
		}
		if (sz > n/2) {
			continue;
		}
		else {
			for (int i = 0; i < n && sz < n/2; i++) {
				if (ans[i] == '0') {
					ans[i] = '1';
					sz++;
				}
			}
			cout << z << endl <<  ans << endl;
			return 0;
		}
		// for (int j = 0; j < 3; j++) {
		// 	for (int jj = 0; jj < 3; jj++) {
		// 		cerr << dang[j][jj] << ' ';
		// 	}
		// 	cerr << endl;
		// }
		// cerr << endl;
	}
	cout << -1 << endl;
}