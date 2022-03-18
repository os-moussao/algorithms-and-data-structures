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
#define RB rbegin()
#define E end()
#define RE rend()
#define ALL(a) a.B, a.E
#define RALL(a) a.RB, a.RE
#define nn '\n'
#define ss ' '

int best(vi arr, int a) {
	int ret = 1e10;
	FOR(i, arr.SZ)
		ret = min(ret, abs(a - arr[i]));
	return ret;
}

void solve()
{
	int n; cin >> n;
	vi a(n), b(n);
	FOR (i, n) cin >> a[i];
	FOR (i, n) cin >> b[i];

	vi a1 = {abs(a[0] - b[0]), best(b, a[0]), abs(a[0] - b[n - 1])};
	vi aN = {abs(a[n - 1] - b[0]), best(b, a[n - 1]), abs(a[n - 1] - b[n - 1])};
	int b1 = best(a, b[0]);
	int bN = best(a, b[n - 1]);

	// a1 b1 ; an bn
	// a1 bn ; an b1
	// a1 best ; an b1 ; bN
	// a1 best ; an bN ; b1
	// a1 best ; an best ; b1 ; bn
	// an best ; a1 b1 ; bN
	// an best ; a1 bN ; b1
	cout << min(
		{
			a1[0] + aN[2],
			a1[2] + aN[0],
			a1[1] + aN[0] + bN,
			a1[1] + aN[2] + b1,
			a1[1] + aN[1] + bN + b1,
			aN[1] + a1[0] + bN,
			aN[1] + a1[2] + b1
		}
	) << nn;
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

	// vi connected(2, 0); // B1, Bn
	// int ans = 0, best = 1e9 + 10;
	// // case A1
	// best = 1e9 + 10;
	// FOR(i, n) {
	// 	if (abs(a[0] - b[i]) < best)
	// 	{
	// 		best = abs(a[0] - b[i]);
	// 		if (i == 0)
	// 			connected[0] = 1;
	// 		else if (i == n - 1)
	// 		{
	// 			connected[1] = 1;
	// 			connected[0] = 0;
	// 		}
	// 		else connected[0] = 0;
	// 	}
	// }
	// ans += best;
	// // case An
	// best = 1e9 + 10;
	// bool del = 0;
	// FOR(i, n) {
	// 	if (abs(a[n - 1] - b[i]) < best)
	// 	{
	// 		if (i == 0 && b[0] == b[n - 1])
	// 			continue ;
	// 		best = abs(a[n - 1] - b[i]);
	// 		if (i == 0)
	// 		{
	// 			del = connected[0] != 1;
	// 			connected[0] = 1;
	// 		}
	// 		else if (i == n - 1)
	// 		{
	// 			connected[1] = 1;
	// 			if (del)
	// 				connected[0] = 0;
	// 		}
	// 		else if (del)
	// 			connected[0] = 0;
	// 	}
	// }
	// ans += best;
	// if (!connected[0]) {
	// 	best = 1e9 + 10;
	// 	FOR(i, n) {
	// 		if (abs(b[0] - a[i]) < best)
	// 			best = abs(b[0] - a[i]);
	// 	}
	// 	ans += best;
	// }
	// if (!connected[1]) {
	// 	best = 1e9 + 10;
	// 	FOR(i, n) {
	// 		if (abs(b[n - 1] - a[i]) < best)
	// 			best = abs(b[n - 1] - a[i]);
	// 	}
	// 	ans += best;
	// }
	// cout << ans << nn;


// void solve()
// {
// 	int n; cin >> n;
// 	vi a(n), b(n);
// 	FOR (i, n) cin >> a[i];
// 	FOR (i, n) cin >> b[i];

// 	vvi connected(2, vi(2, 0));
// 	int ans = 0, best;
	
// 	// A1
// 	best = abs(a[0] - b[0]);
// 	connected[0][0] = 1;
// 	REP (i, 1, n - 1) {
// 		if (abs(a[0] - b[i]) < best)
// 		{
// 			best = abs(a[0] - b[i]);
// 			connected[0][0] = 0;
// 		}
// 	}
// 	if (abs(a[0] - b[n - 1]) < best)
// 	{
// 		best = abs(a[0] - b[n - 1]);
// 		connected[0][1] = 1;
// 		connected[0][0] = 0;
// 	}
// 	ans += best;


// 	// An
// 	best = abs(a[n - 1] - b[n - 1]);
// 	connected[1][1] = 1;
// 	RREP (i, n - 2, 1) {
// 		if (abs(a[n - 1] - b[i]) < best)
// 		{
// 			best = abs(a[n - 1] - b[i]);
// 			connected[1][1] = 0;
// 		}
// 	}
// 	if (abs(a[n - 1] - b[0]) < best)
// 	{
// 		best = abs(a[n - 1] - b[0]);
// 		connected[1][0] = 1;
// 		connected[1][1] = 0;
// 	}
// 	ans += best;

// 	// B1
// 	if (!connected[0][0] && !connected[1][0]) {
// 		best = 1e10;
// 		REP(i, 1,  n -1) {
// 			if (abs(b[0] - a[i]) < best)
// 				best = abs(b[0] - a[i]);
// 		}
// 		ans += best;
// 	}

// 	// Bn
// 	if (!connected[0][1] && !connected[1][1]) {
// 		best = 1e10;
// 		REP(i, 1, n - 1) {
// 			if (abs(b[n - 1] - a[i]) < best)
// 				best = abs(b[n - 1] - a[i]);
// 		}
// 		ans += best;
// 	}
	
// 	cout << ans << nn;
// }

// 10 1 1 10
// 15 9 9 15