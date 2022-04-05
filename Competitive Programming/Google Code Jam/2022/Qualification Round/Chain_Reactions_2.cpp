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
void    setIO(string s);

class Graph {

public:
	// Number of vertecies
	int V;

	// Number of Directed and Undirected edges
	int DE = 0, UE = 0;

	// Number of connected components
	int cnt;

	// Check if a pair of vertecies is connected
	// map <pair<int, int>, bool> conn;

	// Graph's Adjaency list
	vector<vector<int>> adj;

	// Default constructors
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

	// make visited vector
	vector <bool> make_vis(void) {
		return vector <bool> (V, false);
	}

	// Run breath-first search
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

	// Run depth-first search - iterative
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

	// Run depth-first search - recursive
	void DFS_rc(int s, vector <bool> &visited) {
		visited[s] = true;
		cout << s << endl;
		for (int u: adj[s]) {
			if (!visited[u]) {
				DFS_rc(u, visited);
			}
		}
	}

	// Count the number of connected components in the graph
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

	// Topological sort (has to be a directed graph)
	void TP(int s, vector <bool> &visited, stack <int> &S) {
		visited[s] = true;
		
		for (int u: adj[s]) {
			if (!visited[u])
				TP(u, visited, S);
		}
		
		S.push(s);
	}

	void TP_sort(void) {
		vector <bool> vis = make_vis();
		stack <int> S;

		for (int i = 0; i < V; i++) {
			if (!vis[i]) TP(i, vis, S);
		}

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

	// print graph
	void print(void) {
		cout << "Vertecies: " << V << "  Undirected Edges: " << UE << "  Directed Edges: " << DE << '\n';
		for (int i = 0; i < V; i++) {
			cout << i << ": ";
			for (int u: adj[i]) {
				cout << u << ' ';
			}
			cout << '\n';
		}
	}
};

vi f;
vb visited;
Graph g;
// vi dp;
// int mx_sum = 0;
// int sum = 0;
// int mx = 0;

// <max_fun, sum>
pi fun_dfs(int s) {
	if (!g.adj[s].SZ) return MP(f[s], 0);
	
	int min_fun = 0, sum = 0;
	
	FOR(i, g.adj[s].SZ) {
		pi tmp = fun_dfs(g.adj[s][i]);
		if (i == 0)  min_fun = tmp.first;
		min_fun = min(min_fun, tmp.first);
		sum += tmp.first + tmp.second;
	}
	return (MP(max(f[s], min_fun), sum - min_fun));
}

void solve()
{
	int n;
	cin >> n;
	f = vi(n + 1); f[0] = 0;
	visited = vb(n + 1, 0);
	g = Graph(n + 1);
	// dp = vi(n + 1);
	FOR (i, n) cin >> f[i + 1];
	FOR (i, n) {
		int x;
		cin >> x;
		g.edge(x, i + 1);
	}
	pi res = fun_dfs(0);
	cout << res.F + res.S << nn;
}

bool MULTY_TEST_CASES = 1;


int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << setprecision(20);
	cout << fixed;
	
	
	int t = 1;
	if (MULTY_TEST_CASES) cin >> t;

	for (int i = 1; i <= t; i++) {
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}


void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}
