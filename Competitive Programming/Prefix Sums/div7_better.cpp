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

	vi prefix(n + 1, 0);
	REP(i, 1, n + 1)
	{
		cin >> prefix[i];
		prefix[i] = (prefix[i - 1] + prefix[i]) % 7;
	}

	vi firstOcc(7, -1);

	int maxi = 0;

	REP(i, 1, n + 1)
	{
		if (firstOcc[prefix[i]] == -1)
			firstOcc[prefix[i]] = i;
		else
			maxi = max(i - firstOcc[prefix[i]], maxi);
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
