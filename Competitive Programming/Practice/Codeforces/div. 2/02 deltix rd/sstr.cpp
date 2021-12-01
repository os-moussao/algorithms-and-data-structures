#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

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

void solve()
{
	int n, q;
	string s;

	cin >> n >> q;
	cin >> s;

	int ans = 0;
	REP(k, 0, n - 2)
	{
		if (s[k] == 'a' && s[k + 1] == 'b' && s[k + 2] == 'c')
			ans++;
	}


	REP(i, 0, q)
	{
		int a = 0, aa = 0;
		int j;
		int k;
		char c;

		cin >> j >> c;
		
		j--;
		// I need to check if 'abc' exists
		// before and after
		k = (s[j] == 'a')? j: (s[j] == 'b')? j - 1: j - 2;

		if (!(k < 0 || k + 2 >= n))
			a = s[k] == 'a' && s[k + 1] == 'b' && s[k + 2] == 'c';
		
		s[j] = c;

		k = (s[j] == 'a')? j: (s[j] == 'b')? j - 1: j - 2;

		if (!(k < 0 || k + 2 >= n))
			aa = s[k] == 'a' && s[k + 1] == 'b' && s[k + 2] == 'c';

		ans += aa - a;
		cout << ans << nn;
	}
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
