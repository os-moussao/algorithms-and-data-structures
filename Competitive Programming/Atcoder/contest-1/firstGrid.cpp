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

void solve()
{
	string s1, s2;

	cin >> s1 >> s2;

	bool ans =  ((s1[0] == '#' || s2[1] == '#') && (s2[0] == '#' || s1[1] == '#'));

	cout << (ans? "Yes\n":"No\n");
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
