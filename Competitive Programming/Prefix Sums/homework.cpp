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

void solve()
{
	int n;
	cin >> n;

	vi arr(n);
	REP(i, 0, n) cin >> arr[i];

	vi ans(0);

	int div = 1;
	int mini = min(arr[n - 1], arr[n - 2]);
	int sum = arr[n - 1] + arr[n - 2];
	double maxAvg = (double)(sum - mini) / (double) div;

	ans.PB(n - 2);
	for (int i = n - 3; i >= 1; i--)
	{
		mini = min(mini, arr[i]);
		sum += arr[i];
		div++;
		double avg = (double)(sum - mini) / (double)div;
		if (avg == maxAvg)
			ans.PB(i);
		else if (avg > maxAvg)
		{
			maxAvg = avg;
			ans.clear();
			ans.PB(i);
		}
	}

	for (int i = ans.SZ - 1; i >= 0; i--)
		cout << ans[i] << nn;
}

int32_t main()
{
	int t;

	FILE *in = freopen("homework.in", "r", stdin);
	FILE *out = freopen("homework.out", "w", stdout);
	t = 1;
	while (t--) {
		solve();
	}

	fclose(in);
	fclose(out);

	return 0;
}
