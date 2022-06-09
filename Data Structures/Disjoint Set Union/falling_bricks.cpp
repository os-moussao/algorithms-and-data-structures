// task: https://leetcode.com/problems/bricks-falling-when-hit/

typedef vector <int> vi;
typedef vector <vi> vvi;

class DSU {
	public:
		int n;
		vector <int> par;
		vector <int> sz;
		int cnt;
		DSU(){}
		DSU(int N) {
			n = cnt = N;
			par.resize(n); sz.resize(n);
			while (N--) {
				par[N] = N;
				sz[N] = 1;
			}
		}
		int find(int p) {
			return par[p] == p? p: par[p] = find(par[p]);
		}
		bool connected(int p, int q) {
			return find(p) == find(q);
		}
		int size(int p) {
			return sz[find(p)];
		}
		bool join(int p, int q) {
			int root1 = find(p);
			int root2 = find(q);
			if (root1 == root2) return 0;
			if (sz[root1] < sz[root2]) swap(root1, root2);
			par[root2] = root1;
			sz[root1] += sz[root2];
			cnt--;
			return 1;
		}
};

int d1[4] = {1, -1, 0, 0}, d2[4] = {0, 0, 1, -1};

class Solution {
public:
	vector<int> hitBricks(vector<vector<int>> &grid, vector<vector<int>> &hits) {
		int n = grid.size(), m;
		m = n? grid[0].size(): 0;
		auto ind = [&](int i, int j) { return i*m + j; };
		DSU dsu(n*m+1); dsu.sz[dsu.find(ind(n, 0))] = 0;
		int skip[hits.size()]; memset(skip, 1, sizeof skip);
		for (int k = 0; k < hits.size(); k++) {
			int i = hits[k][0], j = hits[k][1];
			if (grid[i][j]) skip[k] = 0;
			grid[i][j] = 0;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (i == 0) dsu.join(ind(n, 0), ind(i, j));
				if (!grid[i][j]) {(dsu.sz[dsu.find(ind(i, j))])--; continue; }
				for (int d = 0; d < 4; d++) {
					int ai = i + d1[d], aj = j + d2[d];
					if (ai < 0 || ai >= n || aj < 0 || aj >= m || !grid[ai][aj]) continue ;
					dsu.join(ind(i, j), ind(ai, aj));
				}
			}
		}
		vi res; res.resize(hits.size());
		for (int ii = hits.size() - 1; ii >= 0; ii--) {
			int i = hits[ii][0], j = hits[ii][1];
			if (skip[ii]) {
				res[ii] = 0;
				continue ;
			}
			int sz = dsu.size(ind(n, 0));
			grid[i][j] = 1;
			(dsu.sz[dsu.find(ind(i, j))])++;
			for (int d = 0; d < 4; d++) {
				int ai = i + d1[d], aj = j + d2[d];
				if (ai < 0 || ai >= n || aj < 0 || aj >= m || !grid[ai][aj]) continue ;
				dsu.join(ind(i, j), ind(ai, aj));
			}
			res[ii] = dsu.size(ind(n, 0)) - sz;
			res[ii] -= res[ii]? 1: 0;
		}
		return res;
	}
};

