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
void    setIO(string s);

int r, c;

void solve() {
	FOR (i, r) {
		FOR (j, c) {

			if (i < 2 && j < 2) {
				cout << '.';
			}
			
			else if (i & 1) {
				cout << (j & 1? '.': '|');
			}

			else {
				cout << (j & 1? '-': '+');
			}

		}
		cout << nn;
	}
}

int MULTY_TEST_CASES = 1;

int32_t main()
{
	int t = 1;
	if (MULTY_TEST_CASES) cin >> t;

	for (int i = 1; i <= t; i++) {
		cout << "Case #" << i << ":\n";
		cin >> r >> c;
		r *= 2; r++;
		c *= 2; c++;
		solve();
	}
	return 0;
}


void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}
