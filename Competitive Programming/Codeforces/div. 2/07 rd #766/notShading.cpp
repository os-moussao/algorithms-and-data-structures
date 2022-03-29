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

void solve()
{
	int m, n, r, c;
	cin >> n >> m >> r >> c;
	r--; c--;
	vector<string> bd(n);
	FOR(i, n) cin >> bd[i];
	int ans = (bd[r][c] == 'B') - 1;
	if (ans == -1) {
		FOR(i, n) {
			FOR(j, m) {
				if (bd[i][j] == 'B') {
					if (i == r || j == c) {
						ans = 1;
						break ;
					} else {
						ans = 2;
					}
				}
			}
			if (ans == 1) {
				break ;
			}
		}
	}
	cout << ans << nn;
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
