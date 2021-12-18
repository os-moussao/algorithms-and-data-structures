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
	int n;
	cin >> n;
	vi arr(n);
	FOR(i, n) cin >> arr[i];

	FOR(i, n)
	{
		int d = arr[i];
		int res;
		bool found = 1;
		int tmp;
		for (int j = 0; j < n; j += 2)
		{
			tmp = (arr[j] % d) != 0;
			if (j == 0) res = tmp;
			else if (tmp != res) {
				found = 0;break ; }
		}
		for (int k = 1; k < n; k+= 2)
		{
			tmp = (arr[k] % d) != 0;
			if (tmp == res)
			{
				found = 0;
				break ;
			}
		}
		if (found) {
			cout << d << nn;
			return ;
		}
	}
	cout << 0 << nn;
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
