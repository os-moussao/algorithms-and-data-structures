// http://usaco.org/index.php?page=viewproblem2&cpid=595
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

	vi arr(n + 1, 0);
	vi ans(7, 0);

	REP(i, 1, n + 1)
	{
		cin >> arr[i];

		arr[i] += arr[i - 1];
		arr[i] %= 7;
	}

	REP(i, 0, 7)
	{
		bool found = 0;
		int min = n + 2;
		int max = -1;
		REP(j, 1, n + 1)
		{
			if (arr[j] == i)
			{
				found = 1;
				max = j;
				if (j < min)
					min = j;
			}
		}
		if (!found)
			ans[i] = 0;
		else
			ans[i] = max - min;
	}

	int max = 0;

	REP(i, 0, 7)
	{
		if (ans[i] > max)
			max = ans[i];
	}
	cout << max << nn;
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
