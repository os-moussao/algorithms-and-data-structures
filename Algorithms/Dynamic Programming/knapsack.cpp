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
typedef vector<int> vi;
template<class T> bool ckmin(T& a, const T b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T b) { return a < b ? a = b, 1 : 0; }

struct wv {
	int w;
	int c;
};

int knapsack(int cap, vector <wv> &a, vector <bool> &taken)
{
	if (cap == 0) return 0;
	int ans = 0;
	for (int i = 0; i < a.size(); i++) {
		if (a[i].w <= cap && !taken[i]) {
			taken[i] = 1;
			ckmax(ans, a[i].c + knapsack(cap - a[i].w, a, taken));
			taken[i] = 0;
		}
	}
	return ans;
}

vector <vi> dp;
int knapsack(int cap, vector <wv> &a, int sz)
{
	if (dp[sz][cap] != -1) return dp[sz][cap];
	
	if (!sz || !cap) return dp[sz][cap] = 0;

	if (a[sz - 1].w > cap) return dp[sz][cap] = knapsack(cap, a, sz - 1);

	return dp[sz][cap] = max(knapsack(cap, a, sz - 1), a[sz - 1].c + knapsack(cap - a[sz - 1].w, a, sz - 1));
}

void solve() {
	int n, m = 0; cin >> n;
	vector <wv> a(n);
	for (int i = 0; i < n; i++) cin >> a[i].w >> a[i].c, m += a[i].w;
	dp = vector<vi>(n + 1, vi(m + 1, - 1));
	for (int i = 1; i <= m; i++) {
		cout << knapsack(i, a, a.size()) << " ";
	}
}

void solve(int vd) {
	(void)vd;
	int n, m = 0; cin >> n;
	vector <wv> a(n);
	for (int i = 0; i < n; i++) cin >> a[i].w >> a[i].c, m += a[i].w;
	dp = vector<vi>(n + 1, vi(m + 1, 0));
	for (int sz = 1; sz <= n; sz++) {
		for (int cap = 1; cap <= m; cap++) {
			if (a[sz - 1].w > cap) dp[sz][cap] = dp[sz - 1][cap];
			else {
				dp[sz][cap] = max(dp[sz - 1][cap], a[sz - 1].c + dp[sz - 1][cap - a[sz - 1].w]);
			}
		}
	}
	for (int cap = 1; cap <= m; cap++) {
		cout << dp[n][cap] << " ";
	}
}

int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << setprecision(20);
	cout << fixed;

	solve(1);
}
