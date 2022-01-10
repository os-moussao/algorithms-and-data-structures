#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <math.h>

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
	int n, k; cin >> n >> k;
	string s; cin >> s;
	map <char, int> h;
	int db = 0, ndb = 0;
	FOR(i, n) {
		h[s[i]]++;
		if (!(h[s[i]]&1)) db++;
	}
	ndb = n - 2 * db;
	// cout << db << ss << ndb << nn;
	if (ndb == 0 || k > n / 2)
		cout << n / k << nn;
	else
		cout << (db / k) * 2 + ((db%k != 0 && ndb >= db / k - 1) || ndb >= k) << nn;
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
