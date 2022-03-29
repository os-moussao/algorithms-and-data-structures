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
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef pair<double, double> pdd;
typedef pair<char, int> pci;
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
#define ALL(a) a.B, a.E
#define nn '\n'
#define ss ' '

void solve()
{
	int n; cin >> n; int ans = 0;
	vi arr(n);
	FOR (i, n) {
		cin >> arr[i];
	}
	REP (i,1, n-1) {
		if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
			if (i + 2 < n) {
				arr[i + 1] = max(arr[i], arr[i + 2]);
			} else {
				arr[i + 1] = arr[i];
			}
			ans++;
		}
	}
	cout << ans<<nn;
	FOR(i, n) {
		cout << arr[i] << ss; 
	}
	cout << nn;
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
