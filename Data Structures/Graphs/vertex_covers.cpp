// problem: https://codeforces.com/problemset/problem/687/A

// the idea that solved the problem for me was knowing that
// each vertex should be in the opposit group ("the enemy") of all of its neighbor
// and if at some point that rule was not possible the output is immediately -1
// else we continues making the groups

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

map <pi, bool> covered;
vvi graph;
vi vertex_cover[2];
vi  cover;
vb vis;

bool make_covers(int vertex, int par)
{
	if (graph[vertex].SZ == 0) return (vis[vertex] = 1, 1);

	if (vis[vertex]) {
		if (par != -1 && cover[vertex] == cover[par])
			return 0;
	}

	if (par != -1)
		cover[vertex] = !cover[par];
	else
		cover[vertex] = 0; // default

	vis[vertex] = 1;

	for (int neighbor: graph[vertex])
	{
		if (vis[neighbor]) {
			if (cover[vertex] == cover[neighbor]) {
				return 0;
			}
			continue ;
		}

		if (!make_covers(neighbor, vertex))
			return 0;
	}

	return 1;
}


void solve()
{
	int n, m; cin >> n >> m;
	graph = vvi(n);
	cover = vi(n, -1);
	vis = vb(n);
	FOR (i, m) {
		int x, y; cin >> x >> y;
		graph[x - 1].PB(y - 1);
		graph[y - 1].PB(x - 1);
	}

	FOR (v, n) {
		if (!vis[v]) {
			if (!make_covers(v, -1))
			{
				cout << -1 << nn;
				return ;
			}
		}
	}

	// FOR (v, n)
	// {
	// 	if (graph[v].SZ == 0) continue ;

	// 	// if (cover[v] == -1)
	// 	// 	cover[v] = 0;

	// 	for (int u: graph[v]) {
	// 		if (covered[MP(u, v)] || covered[MP(v, u)]) {
	// 			if (cover[u] == cover[v]) {
	// 				cout << -1 << nn;
	// 				return ;
	// 			}
	// 		}
	// 		// else {
	// 		// 	cover[u] = !cover[v];
	// 		// 	covered[MP(u, v)] = covered[MP(v, u)] = 1;
	// 		// }
	// 	}
	// }

	FOR (i, n) {
		if (cover[i] != -1)
			vertex_cover[cover[i]].PB(i + 1);
	}

	cout << vertex_cover[0].SZ << nn;
	for (int vc: vertex_cover[0]) cout << vc << ss;
	cout << nn << vertex_cover[1].SZ << nn;
	for (int vc: vertex_cover[1]) cout << vc << ss;
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
