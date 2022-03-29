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

bool isEven(char c)
{
	return (!(c&1));
}

void solve()
{
	string s;
	cin >> s;
	int l = s.length();

	if (isEven(s[l - 1])) {
		cout << 0 << nn;
	}
	else if (isEven(s[0])) {
		cout << 1 << nn;
	}
	else
	{
		REP(i, l) {
			if (isEven(s[i])) {
				cout << 2 << nn;
				return ;
			}
		}
		cout << -1 << nn;
	}
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
