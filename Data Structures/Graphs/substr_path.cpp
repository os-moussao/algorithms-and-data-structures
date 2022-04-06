// problem: https://codeforces.com/problemset/problem/919/D
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

#define int long long
#define double long double

typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef pair<double, double> pdd;
typedef pair<char, int> pci;
typedef vector<pci> vpci;

#define REP(i, a, n) for(int i = a; i < n; i++)
#define FOR(i, n) for(int i = 0; i < n; i++)
#define RREP(i, n, a) for(int i = n; i >= a; i--)
#define RFOR(i, n) for(int i = n; i >= 0; i--)
#define ITER(i, a, b) for(auto i = a; i != b; i++)
#define SZ size()
#define L length()
#define F first
#define S second
#define MP(x, y) make_pair(x, y)
#define PB push_back
#define PF push_front
#define B begin()
#define RB rbegin()
#define E end()
#define RE rend()
#define ALL(a) a.B, a.E
#define RALL(a) a.RB, a.RE
#define nn '\n'
#define ss ' '
#define YESORNO(x) cout << (x? "YES\n": "NO\n")
#define MAXVEC(vec) *max_element(ALL(vec))
#define MINVEC(vec) *min_element(ALL(vec))
#define getunique(vec)  {sort(vec.begin(), vec.end()); vec.erase(unique(vec.begin(), vec.end()), vec.end());}

class Graph {
public:
	int V;
	int DE = 0, UE = 0;
	int cnt;
	// map <pair<int, int>, bool> conn;
	vector<vector<int>> adj;
	Graph(){V = DE = UE = cnt = 0;};
	Graph(int n) {
		V = n;
		adj.resize(n);
	}
	// Add edge
	void edge(int u, int v) {
		adj[u].push_back(v);
		DE++;
		// conn[make_pair(u, v)] = 1;
	}
	// Add undirected edge
	void uedge(int u, int v) {
		adj[u].push_back(v);
		adj[v].push_back(u);
		DE += 2;
		UE++;
		// conn[make_pair(u, v)] = 1;
		// conn[make_pair(v, u)] = 1;
	}
	vector <bool> make_vis(void) {
		return vector <bool> (V, false);
	}
	void BFS(int s, vector <bool> &visited) {
		queue <int> Q;
		Q.push(s);
		visited[s] = true;
		while (!Q.empty()) {
			int v = Q.front(); Q.pop();
			cout << v << endl;
			for (int u: adj[v]) {
				if (!visited[u]) {
					Q.push(u);
					visited[u] = true;
				}
			}
		}
	}
	void DFS_it(int s, vector <bool> &visited) {
		stack <int> S;
		S.push(s);
		visited[s] = true;
		while (!S.empty())
		{
			int v = S.top(); S.pop();
			cout << v << endl;
			for (int u: adj[v]) {
				if (!visited[u]) {
					S.push(u);
					visited[u] = true;
				}
			}
		}
	}
	void DFS_rc(int s, vector <bool> &visited) {
		visited[s] = true;
		cout << s << endl;
		for (int u: adj[s]) {
			if (!visited[u]) {
				DFS_rc(u, visited);
			}
		}
	}
	int connected(void) {
		cnt = 0;
		vector<bool> visited(V, false);
		for (int v = 0; v < V; v++) {
			if (!visited[v]) {
				cnt++;
				DFS_it(v, visited);
			}
		}
		return cnt;
	}
	// TP sort
	void TP(int s, vector <bool> &visited, stack <int> &S) {
		visited[s] = true;
		for (int u: adj[s])
			if (!visited[u]) TP(u, visited, S);
		S.push(s);
	}
	void TP_sort(void) {
		vector <bool> vis = make_vis();
		stack <int> S;
		for (int i = 0; i < V; i++)
			if (!vis[i]) TP(i, vis, S);
		while (!S.empty()) {
			cout << S.top() << ' ';
			S.pop();
		}
	}
	// Cycle detection
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
			if (vis[u] && u == par) return true;
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

int n, m;
Graph G;
string str;
vb  vis;
int mx = -1;

vvi dp;

void   dfs(int s) {
	vis[s] = 1;
	if (!G.adj[s].SZ) {
		dp[s][str[s] - 'a'] = 1;
		return ;
	}
	for (int u: G.adj[s]) {
		if (!vis[u])   dfs(u);
		FOR (i, 26) {
			dp[s][i] = max(dp[s][i], dp[u][i]);
		}
	}
	dp[s][str[s] - 'a']++;
}

void solve()
{
	cin >> n >> m;
	cin >> str;
	G = Graph(n);
	dp = vvi(n, vi(26, 0));
	vis = vb(n, 0);
	FOR (i, m) {
		int x, y; cin >> x >> y; --x, --y;
		G.edge(x, y);
	}
	if (G.dcycle()) {
		cout << -1 << nn;
		return ;
	}
	int mx = -1;
	FOR (i, n) {
		if (!vis[i]) dfs(i);
		mx = max(mx, MAXVEC(dp[i]));
	}
	cout << mx << nn;
}

int32_t main()
{
	int t;

	//cin >> t;
	t = 1;
	while (t--) {
		solve();
	}
	return 0;
}
