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
#define PB push_back
#define PF push_front
#define B begin()
#define E end()
#define ALL(a) a.B, a.E
#define nn '\n'
#define ss ' '

void solve()
{
	int n, m; cin >> n >> m;
	vpi q(m);
	map<int, int> h;
	FOR (i, m) {
		cin >> q[i].S >> q[i].F;
		h[q[i].S] = i;
	}
	sort(ALL(q));
	// FOR (i, m) {
	// 	cout << q[i].F << ss << q[i].S << nn;
	// }
	// cout << nn;
	n *= 2;
	vpi arr(n);
	int s = 0;
	FOR(i, n) {
		arr[i].F = q[i].S;
		arr[i].S = q[i].F;
		s += arr[i].S;
	}
	sort(ALL(arr));
	// FOR (i, n) {
	// 	cout << arr[i].F << ss << arr[i].S << nn;
	// }
	// cout << nn;
	int ii = 0, jj = n - 1;
	cout << s << nn;
	FOR (i, n / 2) {
		cout << h[arr[ii++].F] + 1 << ss << h[arr[jj--].F] + 1<< nn;
	}
	cout <<  nn;
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
