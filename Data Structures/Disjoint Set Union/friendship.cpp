// Application 2: https://codeforces.com/problemset/problem/771/A
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

typedef vector<bool> vb;
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
#define YESORNO(x) cout << (x? "YES\n": "NO\n")
#define MAXVEC(vec) *max_element(ALL(vec))
#define MINVEC(vec) *min_element(ALL(vec))
#define getunique(vec)  {sort(vec.begin(), vec.end()); vec.erase(unique(vec.begin(), vec.end()), vec.end());}

class DSU {
public:
	int N = 0, cnt = 0;
	vector <int> par, sz, rnk;
	DSU(int n) {
		N = n;
		cnt = n;
		par.resize(n);
		sz.resize(n);
		rnk.resize(n);
		for (int i = 0; i < n; i++) {
			par[i] = i;
			sz[i] = 1;
			rnk[i] = 0;
		}
	}
	int makeSet(void) {
		N++;
		cnt++;
		par.push_back(N - 1);
		sz.push_back(1);
		rnk.push_back(0);
		return N - 1;
	}
	int find(int p) {
		stack <int> S;
		while (par[p] != p)
		{
			S.push(p);
			p = par[p];
		}
		while (!S.empty()) {
			par[S.top()] = p;
			S.pop();
		}
		return p;
	}
	bool conected(int p, int q) {
		return find(p) == find(q);
	}
	int csize(int p) {
		return sz[find(p)];
	}
	bool unify(int p, int q)
	{
		int root1 = find(p);
		int root2 = find(q);
		if (root1 == root2) return false;
		if (sz[root2] > sz[root1]) swap(root1, root2);
		sz[root1] += sz[root2];
		par[root2] = root1;
		cnt--;
		return true;
	}
	bool unify_by_rnk(int p, int q)
	{
		int root1 = find(p);
		int root2 = find(q);
		if (root1 == root2) return 0;
		if (rnk[root2] > rnk[root1]) swap(root1, root2);
		par[root2] = root1;
		sz[root1] += sz[root2];
		if (rnk[root1] == rnk[root2])
			rnk[root1]++;
		cnt--;
		return 1;
	}
};


void solve()
{
	int n, m;
	cin >> n >> m;
	vi ed(n, 0);
	DSU dsu(n);
	FOR (i, m) {
		int x, y;
		cin >> x >> y;
		--x, --y;
		ed[x]++; ed[y]++;
		dsu.unify(x, y);
	}
	FOR (i, n) {
		if (ed[i] != dsu.csize(i) - 1) {
			cout << "NO\n";
			return ;
		}
	}
	cout << "YES\n";
}

int32_t main()
{
	int t;

	//cin >> t;
	t = 1;
	while (t--) {
		solve();
	}
	return 0;
}
