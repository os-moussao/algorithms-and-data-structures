// Solution for:
// https://cses.fi/problemset/task/1660/ (subarray sums I)
// https://cses.fi/problemset/task/1661/ (subarray sums II) 
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
	int n, k;
	cin >> n >> k;

	int ans = 0;
	map <int, int> hash;
	vi Pre(n + 1);
	Pre[0] = 0;
	hash[0] = 1;
	REP(i, 1, n + 1) {
		cin >> Pre[i];
		Pre[i] += Pre[i - 1];
		if (hash[Pre[i] - abs(k)])
			ans += hash[Pre[i] - abs(k)];
		hash[Pre[i]]++;
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
