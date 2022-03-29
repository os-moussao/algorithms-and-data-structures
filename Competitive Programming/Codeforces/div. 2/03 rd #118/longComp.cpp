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

void solve()
{
	string x, xx;
	int p, pp;
	cin >> x >> p >> xx >> pp;

	int l = x.length() + p;
	int ll = xx.length() + pp;

	if (l == ll)
	{
		int xl = x.length(), xxl = xx.length();
		int i = 0, j = 0;
		while (i < xl && j < xxl)
		{
			if (x[i] != xx[j])
			{
				cout <<  ((x[i] > xx[j])? '>': '<') << nn;
				return ;
			}
			i++, j++;
		}
		while (i < xl)
		{
			if (x[i++] != '0')
			{
				cout <<  '>' << nn;
				return  ;
			}
		}
		while (j < xxl)
		{
			if (xx[j++] != '0')
			{
				cout <<  '<' << nn;
				return ;
			}
		}
		cout << '=' << nn;
	}
	else
		cout << ((l > ll)? '>': '<') << nn;
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
