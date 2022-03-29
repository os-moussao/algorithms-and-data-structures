#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <math.h>

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

void solve()
{
	int a, s;
	cin >> a >> s;

	if (s < a)
	{
		cout << -1 << nn;
		return ;
	}
	int b = 0, exp = 1;
	while (a || s)
	{
		if (s%10 - a%10 >= 0)
		{
			b += (s%10 - a%10)*exp;
			s /= 10;
		}
		else
		{
			if ((s%100-a%10)*exp < 0 || (s%100-a%10) > 9)
			{
				cout << -1 << nn;
				return ;
			}
			b += (s%100 - a%10)*exp;
			s /= 100;
		}
		a /= 10;
		exp *= 10;
	}
	cout << b << nn;
}

int32_t main()
{
	int t;

	cin >> t;
	//t = 1;
	while (t--) {
		solve();
	}
	return 0;
}
