// problem: https://codeforces.com/problemset/problem/1167/C

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
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
#define getunique(v)		{sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());}

/*
running a dfs on each node is O(n^2)
*/

int depth = 0;

// void dfs(vvi &graph, vb &vis, vi &nfs, int s) {
// 	vi group;
// 	stack <int> stak;
// 	stak.push(s);
// 	// depth++;
// 	while (stak.SZ) {
// 		int top = stak.top();
// 		//cout<<top<<endl;
// 		vis[top] = true;
// 		// group.insert(top);
// 		group.PB(top);
// 		stak.pop();
// 		for(int u: graph[top]) {
// 			//int u = graph[top][i];
// 			//cout<<top<<" "<<u<<" "<<vis[u]<<endl;
// 			if (!vis[u]) {
// 				vis[u]=1;
// 				stak.push(u);
// 			}
// 		}
// 	}
// 	for(int i: group) {
// 		nfs[i] = group.SZ;
// 	}
// }

vi group;
vb visited;

void dfs(int u, int g, vvi& graph) {
	group[u] = g;
	visited[u] = 1;
	for(int v: graph[u]) {
		if(visited[v]) continue;
		dfs(v, g, graph);
	}
}

void solve()
{
	int n, m;
	cin >> n >> m;
	group = vi(n);
	visited = vb(n);
	vvi graph(n);

	while (m--) {
		int gn;
		cin >> gn;
		vi grp(gn);

		FOR(i, gn) {
			cin >> grp[i];
			(grp[i])--;
			if (i > 0) {
				graph[grp[i]].push_back(grp[i-1]);
				graph[grp[i - 1]].push_back(grp[i]);
			}
		}
	}

	int g = 0;
	FOR (i, n) {
		if (!visited[i]) dfs(i, ++g, graph);
	}
	vi cntgroup(n+1);
	for(int i=0;i<n;i++) {
		cntgroup[group[i]]++;
	}
	for(int i=0;i<n;i++) {
		cout<<cntgroup[group[i]]<<" ";
	}
	
	cout << nn;
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
