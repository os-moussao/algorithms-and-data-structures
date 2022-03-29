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
	string s; cin >> s;
	RFOR(i, s.L - 2) {
		int n = s[i] + s[i + 1] - 2 * '0';
		if (n >= 10) {
			s[i] = n / 10 + '0';
			s[i + 1] = n % 10 + '0';
			cout << s << nn;
			return ;
		}
	}
	int n = s[0] + s[1] - 2 * '0';
	// if (n >= 10) {
	// 	s[s.L - 2] = n / 10 + '0';
	// 	s[s.L - 1] = n % 10 + '0';
	// } else {
	s[1] = n + '0';
	s.erase(0, 1);
	// }
	cout << s << nn;
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
