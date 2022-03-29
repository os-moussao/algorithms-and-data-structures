#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>
#include <numeric>      // std::iota
#include <algorithm>    // std::sort, std::stable_sort

using namespace std;

#define int long long
#define double long double

#define REP(i, n) for(int i = 0; i < n; i++)
#define nn '\n'
#define ss ' '

const int MOD = 1e9 + 7;

void solve()
{
	int n;
	cin >> n;

	int a[n];
	REP(i, n) cin >> a[i];
	
	vector<int> in(n);
	iota(in.begin(), in.end(), 0);

	sort(in.begin(), in.end(), [&](int i, int j){return a[i] > a[j];});

	int ans[n + 1];
	ans[0] = 1;

	int total = 0;
	int d = 1;
	REP(i, n) {
		if (!(i&1)) {
			ans[in[i] + 1] = ans[0] + d;
		}
		else
		{
			ans[in[i] + 1] = ans[0] - d;
			d++;
		}
		total += 2 * abs(ans[in[i] + 1] - ans[0]) * a[in[i]];
	}

	cout << total << nn;
	REP(i, n + 1) cout << ans[i] << ss;
	cout << nn;
}

int32_t main()
{
	int t;

	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
