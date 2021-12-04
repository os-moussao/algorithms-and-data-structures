// https://codeforces.com/problemset/problem/313/B
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

#define int long long
#define double long double

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;

#define REP(i, a, n) for(int i = a; i < n; i++)
#define SZ size()
#define LN length()
#define F first
#define S second
#define PB push_back
#define PF push_front
#define B begin()
#define E end()
#define nn '\n'
#define ss ' '

const int MOD = 1e9 + 7;

void solve()
{
	string s;
	cin >> s;

	vi sums(s.LN + 1);
	sums[0] = sums[1] =  0;

	REP(i, 2, s.LN + 1)
		sums[i] = sums[i - 1] + (s[i - 1] == s[i - 2]);

	int n;
	cin >> n;
	REP(i, 0, n)
	{
		int l, r;
		cin >> l >> r;
		cout << sums[r] - sums[l] << nn;
	}
}

int32_t main()
{
	int t = 1;
	while (t--) {
		solve();
	}
	return 0;
}
