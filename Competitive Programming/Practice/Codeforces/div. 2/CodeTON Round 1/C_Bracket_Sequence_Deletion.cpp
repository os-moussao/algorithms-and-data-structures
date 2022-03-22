#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
#include <algorithm>
#include <stdlib.h>
#include <cstring>

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

void solve()
{
	int n;
	cin >> n;
	char s[n + 1];
	memset(s, 0, n + 1);
	scanf("%s", s);
	char *str = (char *)s;
	// string str;
	// cin >> str;

	int bal = 0;
	int ans = 0;
	int i = 0;
	while (i < n) {
		if  (bal >= 0) {
			bal += (str[i] == '(')? 1: -1;
		}
		if (bal == 0 || (i >= 1 && str[i] == str[0])) {
			str += i + 1;
			// str = str.substr(i + 1);
			// cout << str << ss << i << ss << nn;
			n -= i + 1;
			bal = 0;
			i = -1;
			ans++;
		}
		i++;
	}
	cout << ans << ss <<  n <<  nn;
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
