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
