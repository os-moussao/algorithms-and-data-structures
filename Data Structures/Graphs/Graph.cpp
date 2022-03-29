#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <map>

using namespace std;

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

int main()
{
	cout << "================== Test 1 ===================\n";
	Graph graph = Graph(5);

	graph.uedge(1, 2);
	graph.uedge(2, 3);
	graph.uedge(1, 4);
	graph.uedge(3, 4);
	graph.uedge(4, 0);

	graph.print();
	cout << '\n';
	vector <bool> vis = graph.make_vis();
	graph.DFS_it(1, vis);

	fill(vis.begin(), vis.end(), 0);

	cout << endl;
	graph.DFS_rc(1, vis);

	cout << "\n================== Test 2 ===================\n";

	// testing topological sort with a directed graph
	Graph dir_graph(5);
	dir_graph.edge(0, 1);
	dir_graph.edge(0, 4);
	dir_graph.edge(0, 3);
	dir_graph.edge(1, 2);
	dir_graph.edge(3, 4);
	dir_graph.edge(4, 2);

	dir_graph.print();

	cout << "\nTopological sort: ";
	dir_graph.TP_sort();
	cout << '\n';
}
