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

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef vector<bool> vb;

#define MP(x, y) make_pair(x, y)
#define ALL(a) a.begin(), a.end()
#define RALL(a) a.rbegin(), a.rend()
#define YESORNO(x) cout << (x? "YES\n": "NO\n")
#define MAXVEC(vec) *max_element(ALL(vec))
#define MINVEC(vec) *min_element(ALL(vec))
#define getunique(vec) {sort(vec.begin(), vec.end()); vec.erase(unique(vec.begin(), vec.end()), vec.end());}

template<class T> bool ckmin(T& a, const T b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T b) { return a < b ? a = b, 1 : 0; }
template<class T> bool ft_swap(T &mn, T &mx) {return mn > mx? (swap(mn, mx), 1): 0;}

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

Graph g;
string col;

pi dfs(int s, int &ans) {
	int black = (col[s] == 'B'), white = (col[s] == 'W');
	for (int u: g.adj[s]) {
		pi res = dfs(u, ans);
		black += res.first, white += res.second;
	}
	ans += (black == white);
	return {black, white};
}

void solve()
{
	int n; cin >> n;
	g = Graph(n);
	for (int i = 1; i < n; i++) {
		int x; cin >> x;
		g.edge(--x, i);
	}
	cin >> col;
	int ans = 0;
	dfs(0, ans);
	cout << ans << endl;
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