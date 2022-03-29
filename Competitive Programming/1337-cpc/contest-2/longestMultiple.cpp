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
#define CFOR(i, Condition) for(int i = 0; Condition; i++)
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
	return res % mod;
}
 
bool valid(vi &Pre, int n, int k, int MOD)
{
	int exp = power(10, k, MOD);
	if (Pre[k - 1] == 0) return 1;
	REP(i, 1, n - k + 1)
	{
		if (Pre[i + k - 1] == (Pre[i - 1] * exp) % MOD)
			return 1;
	}
	return 0;
}
 
void solve()
{
	string s;
	int MOD;
	cin >> s >> MOD;
 
	vi Pre(s.L); Pre[0] = (s[0] - '0') % MOD;
	REP(i, 1, s.L)
	{
		int d = s[i] - '0';
		Pre[i] = ((Pre[i - 1] * 10) % MOD + d) % MOD;
	}
 
	int lo = 1, hi = s.L, ans = 0, mid;
	while (lo <= hi)
	{
		mid = lo + (hi - lo) / 2;
		if (valid(Pre, s.L, mid, MOD))
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
 
 
/* useless function, but will need it later */
int special(int MOD, string &s)
{
	if (MOD == 1)
		return (s.L);
	else
	{
		RFOR(i, s.L - 1)
			if ((s[i] - '0') % MOD == 0)
				return (i + 1);
	}
	return (0);
}
