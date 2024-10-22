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
