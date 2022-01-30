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
	int n, q, x;
	cin >> n >> q >> x;
	vi A(n);
	FOR (i, n) cin >> A[i];
	FOR (i, q) {
		int c, l, r;
		cin >> c >> l >> r;
		if (c == 1) {
			sort(A.B + l - 1, A.B + r);
			// FOR (i, n) {
			// 	cout << A[i] << ss;
			// }
			// cout << nn;
		} else {
			sort(A.B + l - 1, A.B + r, greater<int>());
			// FOR (i, n) {
			// 	cout << A[i] << ss;
			// }
			// cout << nn;
		}
	}
	FOR (i, n) {
		if (A[i] == x) {
			cout << i + 1;
			return ;
		}
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
