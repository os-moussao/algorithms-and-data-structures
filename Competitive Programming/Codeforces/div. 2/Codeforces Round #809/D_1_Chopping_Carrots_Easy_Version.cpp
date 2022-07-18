#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define double long double
#define endl '\n'

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef vector<bool> vb;

#define MP(x, y) make_pair(x, y)
#define ALL(a) a.begin(), a.end()
#define RALL(a) a.rbegin(), a.rend()
#define YESORNO(x) cout << (x? "YES\n": "NO\n")
#define MAXVEC(vec) *max_element(ALL(vec))
#define MINVEC(vec) *min_element(ALL(vec))
#define getunique(vec) {sort(vec.begin(), vec.end()); vec.erase(unique(vec.begin(), vec.end()), vec.end());}
#define popcount(x) __builtin_popcountll(x);

template<class T> bool ckmin(T& a, const T b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T b) { return a < b ? a = b, 1 : 0; }
template<class T> bool ft_swap(T &mn, T &mx) {return mn > mx? (swap(mn, mx), 1): 0;}

// SRC: Geeks for geeks
// Returns element closest to target in arr[]

int getClosest(int, int, int);
int findClosest(int arr[], int n, int target)
{
	// Corner cases
	if (target <= arr[0])
		return arr[0];
	if (target >= arr[n - 1])
		return arr[n - 1];

	// Doing binary search
	int i = 0, j = n, mid = 0;
	while (i < j) {
		mid = (i + j) / 2;

		if (arr[mid] == target)
			return arr[mid];

		/* If target is less than array element,
			then search in left */
		if (target < arr[mid]) {

			// If target is greater than previous
			// to mid, return closest of two
			if (mid > 0 && target > arr[mid - 1])
				return getClosest(arr[mid - 1],
								arr[mid], target);

			/* Repeat for left half */
			j = mid;
		}

		// If target is greater than mid
		else {
			if (mid < n - 1 && target < arr[mid + 1])
				return getClosest(arr[mid],
								arr[mid + 1], target);
			// update i
			i = mid + 1;
		}
	}

	// Only single element left after search
	return arr[mid];
}

int getClosest(int val1, int val2,
			int target)
{
	if (target - val1 >= val2 - target)
		return val2;
	else
		return val1;
}


void solve()
{
	int n, k; cin >> n >> k;
	vi a(n);
	for (int &i: a) cin >> i;
	// sort(a, a+n);
	int vl[n][k];
	for (int i = 0; i < n; i++) {
		for (int j = k; j >= 1; j--) {
			vl[i][k-j] = a[i]/j;
		}
	}
	// for (int i = 1; i <= k; i++) {
	// 	for (int j = 0; j < n; j++) {
	// 		cerr << vl[j][i-1] << " ";
	// 	}
	// 	cerr << endl;
	// }
	// cerr << endl;
	int ans = 1e9;
	for (int i = 1; i <= k; i++) {
		int tar = vl[0][i-1];
		int mn = tar;
		int mx = tar;
		// cerr << tar << " ";
		for (int j = 1; j < n; j++) {
			int x = findClosest(vl[j], k, (mn + mx) / 2);
			int y = findClosest(vl[j], k, (mn + mx + 1) / 2);
			int anx = max(mx, x) - min(mn, x);
			int any = max(mx, y) - min(mn, y);
			if (any < anx) x = y;
			ckmin(mn, x);
			ckmax(mx, x);
			// cerr << x << " ";
		}
		ckmin(ans, mx-mn);
		// cerr << endl;
		// cerr << mx << " " << mn << " " << tar << endl;
	}
	cout << ans << endl;
}

void preprocessing() {}

bool MULTY_TEST_CASES = 1;

int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << setprecision(20);
	cout << fixed;

	preprocessing();

	int t = 1;
	if (MULTY_TEST_CASES) cin >> t;

	while (t--) {
		solve();
	}
}