#include <iostream>

using namespace std;

#define int long long
#define double long double
#define nn '\n'
#define ss ' '

bool valid(string s, int *hash, int n, int k, int m)
{
	int diff;
	for (int i = 0; i + m - 1 < n; i++)
	{
		diff = hash[i + m - 1] - hash[i] + (s[i] == '1');
		if (min(diff, m - diff) <= k)
			return (true);
	}
	return (false);
}

int32_t main()
{
	int n, k;
	cin >> n >> k;

	string s;
	cin >> s;

	int hash[n];
	hash[0] = (s[0] == '1');
	for (int i = 1; i < n; i++)
		hash[i] = (s[i] == '1') + hash[i - 1];

	int lo = 0, hi = n, mid, ans = 0;

	while (hi >= lo)
	{
		mid = lo + (hi - lo) / 2;
		if (valid(s, hash, n, k, mid))
		{
			ans = mid;
			lo = mid + 1;
		}
		else
			hi = mid - 1;
	}
	cout << ans << nn;
}
