#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

#define int long long
#define double long double

#define REP(i, n) for(int i = 0; i < n; i++)
#define nn '\n'
#define ss ' '

const int MOD = 1e9 + 7;

bool valid(int *hash, string s, int k, int l)
{
	int n = s.length();
	REP(i, n - l + 1)
	{
		int d = hash[i + l - 1] - hash[i] + (s[i] == '.');
		if (d <= k)
			return true;
	}
	return false;
}

void solve()
{
	int	k;
	string s;
	cin >> s >> k;
	
	int lo = 0, hi = s.length(), mid, ans;
	int hash[hi];

	hash[0] = s[0] == '.';
	for (int i = 1; i < hi; i++)
		hash[i] = hash[i - 1] + (s[i] == '.');

	while (hi >= lo)
	{
		mid = lo + (hi - lo) / 2;
		if (valid(hash, s, k, mid))
		{
			lo = mid + 1;
			ans = mid;
		}
		else
			hi = mid - 1;
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
