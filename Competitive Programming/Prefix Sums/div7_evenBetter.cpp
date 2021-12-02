#include <fstream>
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
	int n;
	cin >> n;

	int prefix = 0, maxi = 0;

	vi firstOcc(7, -1);

	REP(i, 0, n)
	{
		int nbr;
		cin >> nbr;

		prefix = (prefix + nbr) % 7;

		if (firstOcc[prefix] == -1)
			firstOcc[prefix] = i;
		else
			maxi = max(i - firstOcc[prefix], maxi);
	}

	cout << maxi << nn;
}

int32_t main()
{
	FILE *in = freopen("div7.in", "r", stdin);
	FILE *out = freopen("div7.out", "w", stdout);

	int t;
	t = 1;
	while (t--) {
		solve();
	}
	fclose(in);
	fclose(out);
}
