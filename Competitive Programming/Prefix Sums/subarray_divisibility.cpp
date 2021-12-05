// https://cses.fi/problemset/task/1662
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

#define int long long
#define double long double

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;

#define REP(i, a, n) for(int i = a; i < n; i++)
#define RREP(i, n, a) for(int i = n; i >= a; i--)
#define IETR(i, a, b) for(auto i = a; i != b; i++)
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
	int n;
	cin >> n;
	
	map<int, int> hash;

	int Pre = 0;
	hash[Pre] = 1;

	int ans = 0;
	REP(i, 2, n + 2)
	{
		int x;
		cin >> x;
		Pre = (Pre + x) % n;
		if (Pre < 0)
			Pre += n;

		if (hash[Pre]++)
			ans += hash[Pre] - 1;
	}
	cout << ans << nn;
}

int32_t main()
{
	int t;

	t = 1;
	while (t--) {
		solve();
	}
	return 0;
}
