// task: https://codeforces.com/gym/103640/problem/F
#include <bits/stdc++.h>

using namespace std;
#define int long long
#define endl '\n'


class DSU {
	public:
		int n;
		vector <int> par;
		vector <int> sz;
		vector <int> sum;
		vector <bool> sel;
		int cnt;
		DSU(){}
		DSU(int N) {
			n = cnt = N;
			par.resize(n); sz.resize(n);
			sum.resize(n); sel.resize(n);
			while (N--) {
				par[N] = N;
				sz[N] = 1;
				sum[N] = (1 << (N + 1));
				sel[N] = 0;
			}
		}
		int find(int p) {
			return par[p] == p? p: par[p] = find(par[p]);
		}
		void select(int p) {
			p = find(p);
			sel[p] = 1;
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
			sum[root1] += sum[root2];
			cnt--;
			return 1;
		}
};

int n, m;
DSU dsu;

void solve()
{
	cin >> n >> m;
	dsu = DSU(n);
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		if (x == n || y == n) {
			continue;
		}
		dsu.join(--x, --y);
	}
	string ans;
	for (int i = 0; i < n; i++) {
		if (dsu.connected(i, n-2)) {
			cout << "B";
		}
		else {
			cout << "A";
		}
	}
}

void preprocessing() {}

bool MULTY_TEST_CASES = 0;

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
	return 0;
}