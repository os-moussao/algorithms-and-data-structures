// link: https://codeforces.com/edu/course/2/lesson/6/3/practice/contest/285083/problem/D
#include <bits/stdc++.h>

using namespace std;
#define int long long 
#define double long double
#define endl '\n'


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

	void print(void) {
		for (int i = 0; i < V; i++) {
			cerr << i << ": ";
			for (int u: adj[i]) {
				cerr << u << ' ';
			}
			cerr << '\n';
		}
	}
};

template<class T> bool ckmin(T &a, const T b) {return b < a? a = b, 1: 0; }

int n, m, d, ans = 1e18;
bool flag = 0;
vector <int> path;
vector <tuple<int, int, int>> edges;

vector <int> BFS(int s, int e, Graph &g) {
	queue <int> Q;
	
	vector <int> par;
	par.resize(n);
	par[s]= -1;

	bool vis[n];
	memset(vis, 0, sizeof vis);

	Q.push(s);
	vis[s] = true;
	while (!Q.empty()) {
		int v = Q.front(); Q.pop();
		if (v == e) {
			vector <int> _path;
			while (v != -1) {
				_path.push_back(v + 1);
				v = par[v];
			}
			return _path;
		}
		for (int u: g.adj[v]) {
			if (!vis[u]) {
				par[u] = v;
				Q.push(u);
				vis[u] = true;
			}
		}
	}
	return {};
}


bool can(int mid) {
	Graph g(n);
	for (int i = 0; i <= mid; i++) {
		int a = get<0>(edges[i]), b = get<1>(edges[i]);
		g.edge(a, b);
	}
	// g.print();
	vector <int> _path = BFS(0, n - 1, g);
	return _path.empty() || _path.size() > d + 1? 0: (path = _path, 1);
}


int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m >> d;
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		--a, --b;
		edges.push_back(make_tuple(a, b, c));
	}
	sort(edges.begin(), edges.end(), [&](const tuple<int, int, int> &a, const tuple<int, int, int> &b){return get<2>(a) < get<2>(b);});
	int lo = 0, hi = edges.size() - 1, ans, mid;
	while (lo <= hi) {
		mid = lo + (hi - lo) / 2;
		if (can(mid)) {
			ans = mid;
			hi = mid - 1;
		}
		else {
			lo = mid + 1;
		}
	}
	if (path.empty()) {
		cout << -1 << endl;
	}
	else {
		reverse(path.begin(), path.end());
		cout << path.size() - 1 << endl;
		for (int u: path) {
			cout << u << " ";
		}
	}
}