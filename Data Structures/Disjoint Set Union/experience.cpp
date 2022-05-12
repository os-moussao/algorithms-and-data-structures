// link: https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/C
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
 
class DSU {
public:
	int N;
	int cnt;
	vector <int> par;
	vector <int> sz;
	vector <int> exp;
	vector <int> tmp;
	vector <vector<int>> adj;
	DSU(){N=0; cnt=0;}
	DSU(int n) {
		N = cnt = n;
		par.resize(n);  sz.resize(n); tmp.resize(n); exp.resize(n); adj.resize(n);
		for (int i = 0; i < n; i++) {
			par[i] = i; sz[i] = 1;
			exp[i] = 0;
			tmp[i] = 0;
			adj[i].push_back(i);
		}
	}
	int find(int p) {
		return (p == par[p]? p: par[p] = find(par[p]));
	}
	int get_exp(int p) {
		int root = find(p);
		return exp[p] + tmp[root];
	}
	void add(int p, int v) {
		tmp[find(p)] += v;
	}
	bool connected(int p, int q) {
		return find(p) == find(q);
	}
	int size(int p) {
		return sz[find(p)];
	}
	bool unify(int p, int q)
	{
		int root1 = find(p);
		int root2 = find(q);
		if (root1 == root2) return 0;
		if (sz[root1] < sz[root2]) swap(root1, root2);
		par[root2] = root1;
		sz[root1] += sz[root2];
		for (int a: adj[root2]) {
			exp[a] += tmp[root2] - tmp[root1];
			adj[root1].push_back(a);
		}
		adj[root2].clear();
		cnt--;
		return 1;
	}
};
 
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m; cin >> n >> m;
	DSU dsu(n);
	while (m--) {
		string s;
		int a, b;
		cin >> s;
		if (s[0] == 'g') {
			cin >> a; a--;
			cout << dsu.get_exp(a) << endl;
		}
		else if (s[0] == 'j') {
			cin >> a >> b; --a, --b;
			dsu.unify(a, b);
		}
		else {
			cin >> a >> b; --a;
			dsu.add(a, b);
		}
	}
}
