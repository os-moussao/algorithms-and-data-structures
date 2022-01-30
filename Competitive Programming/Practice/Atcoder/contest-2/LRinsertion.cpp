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
	int n; cin >> n;
	string s; cin >> s;
	// vi A(n + 1);
	int lp = 0;
	vi A (n + 1, 0);
	FOR(i, n) {
		if (s[i] == 'L') {
			A[lp] = i + 1;
			A[lp + 1] = i;
			// A.insert(A.B + lp, i + 1);
		} else {
			A[lp + 1] = i + 1;
			// A.insert(A.B + lp + 1, i + 1);
			lp++;
		}
	}
	FOR(i, n + 1) {
		cout << A[i] << ss;
	}
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
