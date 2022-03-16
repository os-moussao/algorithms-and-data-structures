// solving: https://codeforces.com/contest/199/problem/D

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
#define YESORNO(x) cout << (x? "YES\n": "NO\n");

int n, k;
map <pi, bool> visited;
queue <pair <pi, int> > q;
bool escape = false;

vpi get_moves(vs &wall, int x, int y, int water)
{
	vpi moves {
		MP(x, y + 1),
		MP(x, y - 1),
		MP(!x, y + k)
	};
	vpi ret;
	FOR (i, 3) {
		if (moves[i].S < 0 || moves[i].S < water || \
		(moves[i].S < n && wall[moves[i].F][moves[i].S] == 'X')) continue;
		ret.PB(moves[i]);
	}
	return ret;
}

void bfs(vs &wall)
{
	if (escape || !q.SZ)
		return ;

	pair <pi, int> p = q.front(); q.pop();
	pi pos = p.F;
	int water = p.S;
	visited[pos] = 1;

	if (pos.S >= n && pos.S >= water) {
		escape = true;
		return ;
	}

	if (pos.S >= water)
	{
		vpi moves = get_moves(wall, pos.F, pos.S, water);

		FOR (i, moves.SZ) {
			if (!visited[moves[i]])
			{
				q.push(MP(moves[i], water + 1));
				visited[moves[i]] = 1;
			}
		}
	}

	return bfs(wall);
}

int32_t main()
{
	int t;

	// freopen("inn", "r", stdin);
	//cin >> t;
	t = 1;
	while (t--) {
		cin >> n >> k;
		vs wall(2);
		cin >> wall[0] >> wall[1];
		// run BFS
		// always check water
		q.push(MP(MP(0, 0), 0));
		bfs(wall);
		YESORNO(escape)
	}
	return 0;
}
