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

int minDis(vi &arr, int d) {
	int minn = arr[0], tmp;
	for (int i = 1; i < arr.SZ; i++) {
		tmp = arr[i] - arr[i - 1];
		if (tmp < minn) {
			minn = tmp;
		}
	}
	return minn;
}

int lastPosMin(vi arr, int d, int min_i) {
	for (int i = min_i + 1; i < arr.SZ; i++) {
		arr[i - 1] = arr[i];
	}
	arr[arr.SZ - 1] = d;
	return minDis(arr, d);
}

int minLargBreak(vi arr, int d, int min_i) {
	// find element before largest break
	int lar = arr[0], lar_i = 0;
	arr.PB(d);
	for (int i = 1; i < arr.SZ; i++) {
		int tmp = 
	}
	// shift and put
	// minDis
}

void solve()
{
	int n, d; cin >> n >> d;
	int minn = 0, min_i;
	vi	arr(n);
	FOR (i, n) {
		if (i < n)
			cin >> arr[i];
		if (i == 0) {
			minn = arr[0];
			min_i = 0;
		}
		else if (arr[i] - arr[i - 1] < minn) {
			minn = arr[i] - arr[i - 1];
			min_i = i;
		}
	}
	int max_min = minn;
	// put in the last position
	int last = 0;
	if (arr[n - 1] != d) {
		last = max(minn, );
	}
	// put between the largest break
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
