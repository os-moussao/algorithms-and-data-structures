#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>

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
	int a, b, c; a = b = c = 0;
	vi arr(n);
	FOR(i, n)
	{
		cin >> arr[i];
		if (arr[i] == 1)
			a++;
		else if (arr[i] == 2)
			b++;
		else
			c++;
	}
	map<int , int> h;
	int ans = min({a, b, c});
	cout << ans << nn;
	FOR(i, ans)
	{
		REP(x, 1, 4)
		{
			FOR(i, n)
			{
				if (arr[i] == x && !h[i])
				{
					cout << i + 1 << ss;
					h[i] = 1;
					break ;
				}
			}
		}
		cout << nn;
	}
}

int32_t main()
{
	int t;

	//cin >> t;
	t = 1;
	while (t--) {
		solve();
	}
	return 0;
}
