// print the shortest path from node A to node B
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

// find shortest path from s to e
vi find_path(vvi &graph, int s, int e)
{
	vi prev_node(graph.SZ, -1); // tracking the previous node of each node (startng from s)
	queue <int> q;
	map<int, bool> visited;
	q.push(s);

	// run BFS
	while (q.SZ > 0 && !visited[e])
	{
		int node = q.front();  q.pop();
		visited[node] = 1;

		// visit neighbors
		for (int i = 0; i < graph[0].SZ; i++) {
			if (graph[node][i] && !visited[i]) {
				prev_node[i] = node;
				visited[i] = 1;
				q.push(i);
			}
		}
	}
	
	// generate path
	if (!visited[e]) return ((vi)0);
	vi path;
	path.PB(e);
	while (prev_node[e] != s) {
		path.PB(prev_node[e]);
		e = prev_node[e];
	}
	path.PB(s);
	reverse(ALL(path));
	return path;
}

int32_t main()
{
	// find the shortest path from 1 to 4 (1 -> 2 -> 4)
	vvi graph = {
		{0, 1, 1, 0, 0, 0, 0},
		{1, 0, 1, 1, 0, 0, 0},
		{1, 1, 0, 1, 1, 0, 0},
		{0, 1, 1, 0, 0, 1, 0},
		{0, 0, 1, 0, 0, 1, 0},
		{0, 0, 0, 1, 1, 0, 0},
		{0, 0, 0, 0, 0, 0, 0},
	};
	
	vi path = find_path(graph, 1, 4);

	if (path == (vi)0) {
		cout << "there is no path\n";
	} else {
		for (int i = 0; i < path.SZ; i++) {
			cout << path[i] << ss;
		}
		cout << nn;
	}
}
