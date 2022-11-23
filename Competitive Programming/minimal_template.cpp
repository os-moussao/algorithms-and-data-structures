#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

#define ALL(a) a.begin(), a.end()
#define RALL(a) a.rbegin(), a.rend()
#define YESORNO(x) cout << (x? "YES\n": "NO\n")
#define SZ(x) (int)(x.size())

template<class T> bool ckmin(T& a, const T b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T b) { return a < b ? a = b, 1 : 0; }

#ifdef LOCAL
#include "debug.hpp"
#else
#define debug(x...)
#endif

void solve(int test_case) {
	
}

int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t; cin >> t;
	for (int i = 1; i <= t; i++) {
		solve(i);
	}
}