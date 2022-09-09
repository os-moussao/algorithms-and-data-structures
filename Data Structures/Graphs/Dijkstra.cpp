#include <algorithm>
#include <iomanip>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

template<class T> bool ckmin(T& a, const T b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T b) { return a < b ? a = b, 1 : 0; }

vector <vector <pair<int, int>>> g;
vector <int> dist;
vector <int> previous;

void dijkstra(int s) {
	int n = g.size();
	dist.assign(n, 1e9);
	previous.assign(n, -1);
	dist[s] = 0;
	set<pair<int, int>> q;
	q.insert({0, s});
	while (!q.empty()) {
		int v = q.begin()->second;
		q.erase(q.begin());

		for (auto edge : g[v]) {
			int to = edge.first;
			int len = edge.second;

			if (dist[v] + len < dist[to]) {
				q.erase({dist[to], to});
				dist[to] = dist[v] + len;
				previous[to] = v;
				q.insert({dist[to], to});
			}
		}
	}
}

// input example:
/*
	7 11
	a c 3
	a f 2
	c f 2
	c e 1
	e f 3
	e b 2
	f b 6
	f g 5
	g b 2
	d b 1
	c d 4
	a b

	should output:
	4 6
	A C E B
*/
int main()
{
	// freopen("in","r",stdin);
	int n, m;
	cin >> n >> m;
	g.resize(n);
	dist.resize(n);
	previous.resize(n);
	for (int i = 0; i < m; i++) {
		char x, y;
		int v;
		cin >> x >> y >> v;
		x -= 'a', y -= 'a';
		g[x].push_back({y, v});
		g[y].push_back({x, v});
	}
	char src, dest;
	cin >> src >> dest;
	src -= 'a'; dest -= 'a';
	dijkstra(src);
	if (dist[dest] == 1e9) {
		cout << -1 << endl;
	} else {
		vector <int> path;
		int v = dest;
		while (v != -1) {
			path.push_back(v);
			v = previous[v];
		}
		reverse(path.begin(), path.end());
		cout << path.size() << ' ' << dist[dest] << endl;
		for (int i: path) {
			cout << char('A'+i) << ' ';
		}
		cout << endl;
	}
}