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
 
class Graph {
public:
	int V;
	vector<vector<int>> adj;
	Graph(){V = 0;};
	Graph(int n) {
		V = n;
		adj.resize(n);
	}
	void edge(int u, int v) {
		adj[u].push_back(v);
	}
	void uedge(int u, int v) {
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	enum state {
		UNVIS,
		IN_STACK,
		VIS
	};
	bool dfs_dcycle(int s, vector<state> &vis)
	{
		vis[s] = IN_STACK;
		for (int u: adj[s]) {
			if (vis[u] == IN_STACK) return true;
			if (vis[u] == UNVIS && dfs_dcycle(u, vis)) return true;
		}
		vis[s] = VIS;
		return false;
	}
	bool dfs_ucycle(int s, vector<bool> &vis, int par) {
		vis[s] = 1;
		for (int u: adj[s]) {
			if (vis[u] && u != par) return true;
			if (!vis[u] && dfs_ucycle(u, vis, s)) return true;
		}
		return false;
	}
	bool dcycle(void) {
		vector<state> vis(V, UNVIS);
		for (int i = 0; i < V; i++) {
			if (vis[i] == UNVIS && dfs_dcycle(i, vis)) return true;
		}
		return false;
	}
	bool ucycle(void) {
		vector<bool> vis(V, 0);
		for (int i = 0; i < V; i++) {
			if (!vis[i] && dfs_ucycle(i, vis, -1)) return true;
		}
		return false;
	}
};
 
 
int n, m, k;
vector<pair<int, int>> edges;
vector<pair <int, int>> values;
 
void dfs(int node, vector<vector<int>> &adj, vector <int> &dp, vector <bool> &vis)
{
    vis[node] = true;
    for (int i = 0; i < adj[node].size(); i++) {
        if (!vis[adj[node][i]])
            dfs(adj[node][i], adj, dp, vis);
        dp[node] = max(dp[node], 1 + dp[adj[node][i]]);
    }
}
int LongestPath(vector <vector <int>> &adj)
{
    vector <int> dp(n+1);
    vector <bool> vis(n+1);
    for (int i = 0; i < n; i++) {
        if (!vis[i])
            dfs(i, adj, dp, vis);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, dp[i]);
    }
    return ans;
}
 
bool can(int ind) {
	Graph g(n);
	bool cancel[n];
	memset(cancel, 0, sizeof cancel);
	for (int i = ind + 1; i < n; i++) {
		cancel[values[i].second] = 1;
	}
	for (pair<int, int> e: edges) {
		int x = e.first, y = e.second;
		if (cancel[x] || cancel[y]) continue;
		g.edge(x, y);
	}
	if (g.dcycle()) return 1;
	return LongestPath(g.adj) >= k-1;
}
 
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k;
	edges.resize(m);
	values.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> values[i].first;
		values[i].second = i;
	}
	sort(values.begin(), values.end());
	for (int i = 0; i < m; i++) {
		int x, y; cin>> x >> y;
		edges[i].first = --x, edges[i].second = --y;
	}
	int lo = 0, hi = n-1, ans, mid;
	bool flag = 0;
	while (lo <= hi) {
		mid = lo + (hi - lo) / 2;
		if (can(mid)) {
			hi = mid-1;
			ans=mid;
			flag = 1;
		}
		else {
			lo = mid + 1;
		}
	}
	cout << (flag?values[ans].first:-1) << endl;
}