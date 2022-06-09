// task: https://leetcode.com/problems/last-day-where-you-can-still-cross/

typedef vector <int> vi;
typedef vector <vi>  vvi;

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

class Solution {
private:
	int d1[4] = {1, -1, 0, 0}, d2[4] = {0, 0, 1, -1};
public:
	int latestDayToCross(int n, int m, vector<vector<int>>& cells) {
		bool grid[n][m]; memset(grid, 1, sizeof grid);
		DSU dsu(m*n+2);
		auto ind = [&](int i, int j) { return i*m + j; };
		int top = ind(n, 0), bott = ind(n, 1);
		for (vi &c: cells) {
			c[0]--, c[1]--;
			int i = c[0], j = c[1];
			grid[i][j] = 0;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!grid[i][j]) continue ;
				int id = ind(i, j);
				if (i == 0) dsu.join(top, id);
				else if (i == n-1) dsu.join(bott, id);
				for (int d = 0; d < 4; d++) {
					int ai = i + d1[d], aj = j + d2[d];
					if (ai < 0 || ai >= n || aj < 0 || aj >= m || !grid[ai][aj]) continue ;
					dsu.join(ind(ai, aj), id);
				}
			}
		}
		for (int day = cells.size() - 1; day >= 0; day--) {
			if (dsu.connected(top, bott)) return day+1;
			int ci = cells[day][0], cj = cells[day][1];
			int id = ind(ci, cj);
			grid[ci][cj] = 1;
			if (ci == 0) dsu.join(top, id);
			else if (ci == n-1) dsu.join(bott, id);
			for (int d = 0; d < 4; d++) {
				int ai = ci + d1[d], aj = cj + d2[d];
				if (ai < 0 || ai >= n || aj < 0 || aj >= m || !grid[ai][aj]) continue ;
				dsu.join(ind(ai, aj), id);
			}
		}
		return 0;
	}
};
