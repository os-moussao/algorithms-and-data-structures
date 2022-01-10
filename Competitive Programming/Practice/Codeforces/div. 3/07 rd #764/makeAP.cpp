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

#include <limits.h>

bool f(int x, int nx)
{
	return (nx >= x && nx % x == 0);
}

void solve()
{
	int	a, b, c; cin >> a >> b >> c;
	int	d1 = b - a, d2 = c - b, d3 = !((c - a)&1)? (c - a)/2: (int)-1e16;
	if (f(c, a + 2 * d1) || f(a, b - d2))
		cout << "YES" << nn;
	else if (d3 != (int)-1e16 && f(b, a + d3))
		cout << "YES" << nn;
	else cout << "NO\n";
	/*
	if (((b + d1)%c == 0 && (b + d1) >= c) || ((b - d1) % a == 0 && b - d1 >= a) ||
		((d3 != INT_MIN) && (a + d3) % b == 0 && (a + d3) >= b)) cout << "YES\n"; else cout << "NO\n";*/
	
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
