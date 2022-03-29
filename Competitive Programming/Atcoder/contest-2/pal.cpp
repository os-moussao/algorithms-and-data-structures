#include <bits/stdc++.h>

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
	string s;
	cin >> s;
	int c = 0;
	for (int i = s.L - 1; i >= 0 && s[i] == 'a'; i--) {
		c++;
	}
	for (int i = 0; i < s.L && s[i] == 'a'; i++) {
		c--;
	}
	if (c > 0)
		s.insert(0, string(c, 'a'));
	// cout << s << nn;
	int i = 0, j = s.L - 1;
	while (i < j) {
		if (s[i++] != s[j--]) {
			cout << "No";
			return ;
		}
	}
	cout << "Yes";
}

int32_t main()
{
	int t;

	//cin >> t;
	t = 1;
	while (t--) {
		solve();
		cout << nn;
	}
	return 0;
}
