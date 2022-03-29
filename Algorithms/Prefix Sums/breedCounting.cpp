// http://usaco.org/index.php?page=viewproblem2&cpid=572
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
#define FST first
#define SND second
#define PB push_back
#define PF push_front
#define B begin()
#define E end()
#define nn '\n'
#define ss ' '

struct breed
{
	vi b{0, 0, 0};
};

void solve()
{
	int n, Q;
	cin >> n >> Q;

	breed arr[n + 1];
	
	REP(i, 1, n + 1)
	{
		int x;
		cin >> x;

		arr[i].b = arr[i - 1].b;

		arr[i].b[x - 1]++; 
	}

	REP(i, 0, Q)
	{
		int a, b;
		cin >> a >> b;

		cout << (arr[b].b[0] - arr[a - 1].b[0]) << ss;
		cout << (arr[b].b[1] - arr[a - 1].b[1]) << ss;
		cout << (arr[b].b[2] - arr[a - 1].b[2]) << nn;
	}
}

// pr link: http://usaco.org/index.php?page=viewproblem2&cpid=572
int32_t main()
{
	int t;

	FILE *in = freopen("bcount.in", "r", stdin);
	FILE *out = freopen("bcount.out", "w", stdout);

	t = 1;
	while (t--) {
		solve();
	}
	return 0;
	fclose(in);
	fclose(out);
}
