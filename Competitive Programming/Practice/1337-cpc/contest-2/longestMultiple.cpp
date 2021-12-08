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
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<char, int> pci;
typedef vector<pii> vpii;
typedef vector<pdd> vpdd;
typedef vector<pci> vpci;

#define REP(i, a, n) for(int i = a; i < n; i++)
#define FOR(i, n) for(int i = 0; i < n; i++)
#define RREP(i, n, a) for(int i = n; i >= a; i--)
#define RFOR(i, n) for(int i = n; i >= 0; i--)
#define ITER(i, a, b) for(auto i = a; i != b; i++)
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

int	power(int a, int b, int mod)
{
	a %= mod;
	int res = 1;
	while (b > 0)
	{
		if (b & 1)
			res = (res * a) % mod;
		a = (a * a) % mod;
		b >>= 1;
	}
	return res;
}

int special(int MOD, string s)
{
	if (MOD == 1)
		return (s.L);
	else // if (MOD == 2 || MOD == 5 || MOD == 10)
	{
		RFOR(i, s.L - 1)
			if ((s[i] - '0') % MOD == 0)
				return (i + 1);
	}
	return (0);
}

void solve()
{
	string s;
	int MOD;
	cin >> s >> MOD;

	if (MOD == 1 || MOD == 10 || MOD == 2 || MOD == 5)
	{
		cout << special(MOD, s) << nn;
		return ;
	}
	vi hash(MOD, -1);
	hash[0] = s.L;

	int ans = 0;
	int m = 0;
	int exp = 1;

	RFOR(i, s.L - 1)
	{
		int digit = s[i] - '0';
		m = ((digit * exp) % MOD + m) % MOD;

		if (hash[m] == -1)
			hash[m] = i;
		else if (MOD % 10 != 0 && 10 % MOD  && power(10, s.L - hash[m] + 1, MOD) != 0)
			ans = max(ans, hash[m] - i);

		exp = (exp * (10 % MOD)) % MOD;
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
