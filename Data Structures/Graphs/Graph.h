#pragma once

class Graph {
	int V;
public:
	vector<vector<int>> adj;
	Graph(): V(0) {};
	Graph(int n) {V = n; adj.resize(n);}
	void edge(int u, int v) {adj[u].push_back(v);}
	void uedge(int u, int v) {edge(u, v); edge(v,u);}
	int  size() {return V;}
	// BFS: shortest path from s to e
	vector <int> BFS(int s, int e) {
		int par[V]; par[s]= -1;
		bool vis[V]; memset(vis, 0, sizeof(vis));
		queue <int> Q; Q.push(s);
		vis[s] = true;
		while (!Q.empty()) {
			int v = Q.front(); Q.pop();
			if (v == e) {
				vector <int> _path;
				while (v != -1) {
					_path.push_back(v); // just v if zero indexed
					v = par[v];
				}
				return (reverse(_path.begin(), _path.end()), _path);
			}
			for (int u: adj[v]) {
				if (!vis[u]) {
					par[u] = v;
					Q.push(u);
					vis[u] = true;
				}
			}
		}
		return {};
	}
	// Cycle detection
	enum state {UNVIS,IN_STACK,VIS};
	bool dcycle(void) {
		vector<state> vis(V, UNVIS);
		for (int i = 0; i < V; i++)
			if (vis[i] == UNVIS && dfs_dcycle(i, vis)) return true;
		return false;
	}
	bool ucycle(void) {
		vector<bool> vis(V, 0);
		for (int i = 0; i < V; i++)
			if (!vis[i] && dfs_ucycle(i, vis, -1)) return true;
		return false;
	}
	stack <int> TP_sort() {
		bool vis[V]; memset(vis, 0, sizeof(vis));
		stack <int> S;
		for (int i = 0; i < V; i++) {
			if (!vis[i]) TP_dfs_helper(i, vis, S);
		}
		return S;
	}
	// connected components
	int ccnt() {
		int cnt = 0;
		bool vis[V]; memset(vis, 0, sizeof(vis));
		for (int v = 0; v < V; v++) {
			if (!vis[v]) { cnt++; DFS(v, vis); }
		}
		return cnt;
	}
	// debug graph
	void print(void) {
		for (int i = 0; i < V; i++) {
			cerr << i << ": ";
			for (int u: adj[i]) cerr << u << ' ';
			cerr << '\n';
		}
	}
private:
	void DFS(int s, bool vis[]) {
		vis[s] = true;
		for (int u: adj[s]) {
			if (!vis[u]) {
				DFS(u, vis);
			}
		}
	}
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
	void TP_dfs_helper(int s, bool vis[], stack<int> &S) {
		vis[s] = true;
		for (int u: adj[s]) {
			if (!vis[u]) TP_dfs_helper(u, vis, S);
		}
		S.push(s);
	}
};

// Longest path in a directed acyclic graph O(N+M)
int ldp_dfs(Graph &g, int s, int dp[], bool vis[]) {
	vis[s] = 1;
	if (dp[s] != -1) return dp[s];
	dp[s] = 0;
	for (int u: g.adj[s]) {
		dp[s] = max(dp[s], 1 + ldp_dfs(g, u, dp, vis));
	}
	return dp[s];
}

int ldp(Graph &g) {
	// dp[i] = ldp starting from i
	int dp[g.size()]; memset(dp, -1, sizeof dp);
	bool vis[g.size()]; memset(vis, 0, sizeof vis);
	int ans = 0;
	for (int i = 0; i < g.size(); i++) {
		if (!vis[i]) ans = max(ans, ldp_dfs(g, i, dp, vis));
	}
	return ans;
}
