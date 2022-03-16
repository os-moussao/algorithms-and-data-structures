// solving: https://codeforces.com/problemset/problem/242/C
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

vpi get_neighbors(map<pi, bool> &allowed, int x, int y)
{
	vi d0 {1, -1, 1, -1, -1, 1, 0, 0};
	vi d1 {1, -1, -1, 1, 0, 0, -1, 1};
	vpi res;
	int xx, yy;
	FOR (i, 8) {
		xx = x + d0[i];
		yy = y + d1[i];
		if (xx < 1 || yy < 1 || xx > 1e9 || yy > 1e9 || !allowed[MP(xx, yy)]) continue ;
		res.PB(MP(xx, yy));
	}
	return (res);
}

int bfs(map<pi, bool> &h, pi s, pi e)
{
	map<pi, bool> vis;
	queue <pi> q;
	map<pi, pi> prev;

	q.push(s);
	while (q.SZ > 0 && !vis[e]) {
		pi curr = q.front(); q.pop();
		vis[curr] = 1;

		vpi neigh = get_neighbors(h, curr.F, curr.S);
		// cout << curr.F << ss << curr.S << nn;
		// cout << neigh.SZ << nn;
		// FOR (i, neigh.SZ) {
		// 	cout << neigh[i].F << ss << neigh[i].S << nn;
		// }
		// exit(1);
		FOR (i, neigh.SZ) {
			if (!vis[neigh[i]])
			{
				prev[neigh[i]] = curr;
				q.push(neigh[i]);
				vis[neigh[i]] = 1;
			}
		}
	}
	if (!vis[e]) return -1;
	int steps = 0;
	while (e != s) {
		// cout << e.F << ss << e.S << nn;
		steps++;
		e = prev[e];
	}
	// cout << e.F << ss << e.S << nn;
	return steps;
}

void solve()
{
	int x0, y0, x1, y1;
	cin >> x0 >> y0 >> x1 >> y1;
	int n; cin >> n;
	map <pi, bool> h;
	FOR (i, n) {
		int r, a, b;
		cin >> r >> a >> b;
		REP (k, a, b + 1) {
			h[MP(r, k)] = 1;
		}
	}
 	cout << bfs(h, MP(x0, y0), MP(x1, y1)) << nn;
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
