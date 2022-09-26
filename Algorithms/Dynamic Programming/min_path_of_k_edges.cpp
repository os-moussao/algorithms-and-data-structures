#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

typedef vector<vector<vector<int>>> vi3d;
typedef vector<vector<int>> vi2d;

// task: https://codeforces.com/gym/102644/problem/F
int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	int LOG = log2(k);
	vi3d adj(LOG+1, vi2d(n, vector<int>(n, 2e18)));
	for (int i = 0; i < m; i++) {
		int x, y, c; cin >> x >> y >> c;
		adj[0][--x][--y]=c;
	}
	for (int i=1; i<=LOG; i++) {
		for (int x=0; x< n; x++) {
			for (int y = 0; y< n; y++) {
				// min to get from x to y in 2^(i) steps
				// is min to get from x to k in 2^(i-1) steps
				// plus min to get from k to y in 2^(i-1) steps
				for (int k = 0; k < n; k++) {
					if (adj[i-1][x][k] != 2e18 && adj[i-1][k][y] != 2e18) {
						adj[i][x][y] = min(adj[i][x][y], adj[i-1][x][k] + adj[i-1][k][y]);
					}
				}
			}
		}
	}
	vector <int> dp(n, 0);
	int log=0;
	while (k) {
		if (k&1) {
			vector<int> newdp(n, 2e18);
			for (int x = 0; x < n; x++) {
				for (int y = 0; y < n; y++) {
					if (adj[log][y][x] != 2e18 && dp[y] != 2e18) {
						newdp[x] = min(newdp[x], dp[y] + adj[log][y][x]);
					}
				}
			}
			dp=newdp;
		}
		k >>= 1;
		log++;
	}
	int ans=*min_element(dp.begin(), dp.end());
	if (ans==2e18) {
		cout << "IMPOSSIBLE\n";
	} else {
		cout << ans << endl;
	}
}