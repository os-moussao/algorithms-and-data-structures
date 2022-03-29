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

// int Mylog2(int n) {
// 	int res = n == 1;
// 	while (n > 1) {
// 		n = (n + 1) / 2;
// 		res++;
// 	}
// 	return res;
// }

void solve()
{
	int n;
	cin >> n;
	map<int, int> h;
	vi arr(n);
	FOR(i, n) {
		cin >> arr[i];
	}
	int x = 1;
	for (int i = n - 2; i >= 0; i--) {
		if (arr[i] == arr[n - 1]) {
			x++;
		}
		else {
			break ;
		}
	}
	int p = x * 2, ans = 0, j = n - x;
	int i = n - p;
	while (i >= 0) {
		for (int k = i; k < j; k++) {
			if (arr[k] != arr[n - 1]) {
				ans++;
				break ;
			}
		}
		j = i;
		p *= 2;
		if (i && n - p < 0) {
			for (int k = 0; k < j; k++) {
				if (arr[k] != arr[n - 1]) {
					ans++;
					break ;
				}
			}
			break ;
		}
		i = n - p;
	}
	cout << ans;
}

int32_t main()
{
	int t;

	cin >> t;
	//t = 1;
	while (t--) {
		solve();
		cout << nn;
	}
	return 0;
}
