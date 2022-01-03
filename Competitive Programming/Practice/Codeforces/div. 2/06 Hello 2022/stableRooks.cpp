#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;

#define int long long
#define double long double

typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<vi> vvi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<char, int> pci;
typedef vector<pii> vpii;
typedef vector<pdd> vpdd;
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
#define PB push_back
#define PF push_front
#define B begin()
#define E end()
#define nn '\n'
#define ss ' '

bool is_stable(vvc bd, int n)
{
	FOR(i, n)
	{
		FOR(j, n)
		{
			if (bd[i][j] == 'R')
			{
			vpii adj{make_pair(i-1, j), make_pair(i+1, j), make_pair(i, j+1), make_pair(i, j-1)};
				FOR(a, 4)
				{
					if (adj[a].F >= n || adj[a].F < 0 || adj[a].S >= n || adj[a].S < 0)
						continue ;
					else
					{
					if (adj[a].F != i)
					{
					 FOR(jj, n) if (bd[adj[a].F][jj] == 'R'/* && (adj[a].F != i && jj != j)*/ ) return 0;
					}
					else 
					{
					 FOR(ii, n) if (bd[ii][adj[a].S] == 'R'/*' && (ii != i && adj[a].S != j)*/) return 0;
					}
					}
				}
			}
		}
	}
	return 1;
}

bool is_save(vvc bd, int i, int j)
{
	FOR(ii, bd.SZ) if (bd[ii][j] == 'R') return 0;
	FOR(jj, bd.SZ) if (bd[i][jj] == 'R') return 0;
	return 1;
}

bool find_sol(vvc bd, int n, int k)
{
	if (k == 0)
	{
		if (is_stable(bd, n))
		{
			FOR(i, n)
			{
				FOR(j, n)
					cout << bd[i][j];
				cout << nn;
			}
			return 1;
		}
		return 0;
	}
	FOR(i, n)
	{
		FOR(j, n)
		{
			if (is_save(bd, i, j))
			{
				bd[i][j] = 'R';
				if (find_sol(bd, n, k - 1))
					return 1;
				bd[i][j] = '.';
			}
		}
	}
	return 0;
}

void solve()
{
	int n, k; cin >> n >> k;
	vvc bd(n, vc(n, '.'));
	if (!find_sol(bd, n, k))
		cout << -1 << nn;
}

int32_t main()
{
	int t;

	cin >> t;
	//t = 1;
	while (t--) {
		solve();
	}
	return 0;
}
