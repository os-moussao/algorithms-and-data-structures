#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
template <class T> using OrderedSet = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
template <class T> using OrderedMultiSet = tree<T, null_type, less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;
#define int long long
#define double long double
#define endl '\n'
#define ALL(a) a.begin(), a.end()
#define RALL(a) a.rbegin(), a.rend()
#define YESORNO(x) cout << (x? "YES\n": "NO\n")
#define SZ(x) (int)(x.size())
template<class T> bool ckmin(T& a, const T b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T b) { return a < b ? a = b, 1 : 0; }

#ifndef ONLINE_JUDGE
#include "debug.hpp"
#else
#define debug(x...)
#endif

#define MULTIPLE_TEST_CASES true
void solve(int testCase) {
  
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  if (MULTIPLE_TEST_CASES) cin >> t;
  while (t--) {
    solve(t);
  }
}