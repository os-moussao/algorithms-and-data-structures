// problem: https://leetcode.com/problems/maximum-height-by-stacking-cuboids/submissions/
#include <algorithm>
#include <array>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

template<class T> bool ckmin(T& a, const T b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T b) { return a < b ? a = b, 1 : 0; }

class Graph {
public:
	vector<vector<int> > adj;
	map <pair<int, int>, bool> connected;
	Graph(){};
	Graph(int n) {
		adj.resize(n);
	}
	void edge(int u, int v) {
		if (!connected[make_pair(v, u)])
			adj[u].push_back(v), connected[make_pair(u, v)] = 1;
	}
	void uedge(int u, int v) {
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
};

// W,L,H
class Solution {
private:
    int n;
	Graph g;
	vector <bool> vis;
public:
	// Directed Acyclic Graph
	int dfs(int s, vector<vector<int> >& boxes) {
		vis[s] = 1;
		int ans = 0;
		for (int u: g.adj[s])
			ckmax(ans, dfs(u, boxes));
		return ans + boxes[s][2];
	}
    int maxHeight(vector<vector<int> >& boxes) {
        n = boxes.size();
        g = Graph(n);
		vis = vector<bool> (n);
		for (auto &box: boxes) sort(box.begin(), box.end());
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (j != i && boxes[j][0] <= boxes[i][0] && boxes[j][1] <= boxes[i][1] && boxes[j][2] <= boxes[i][2]) {
					g.edge(i, j);
				}
			}
		}
		int ret = -1;
		for (int i = 0; i < n; i++)
			if (!vis[i]) ckmax(ret, dfs(i, boxes));
		return ret;
    }
};

int main()
{
	vector<vector <int> > bx = {{50,45,20},{95,37,53},{45,23,12}};
	Solution sol;
	cout << sol.maxHeight(bx) << endl;
}
