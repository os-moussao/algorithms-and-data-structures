#include <bits/stdc++.h>
using namespace std;

#define int long long
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

void solve()
{
	// cerr << "#\n";
	int n; cin >> n;
	vi a(n);
	for (int &i: a) cin >> i;
	vi pre1, pre2;
	int j = 0;
	for (int i = 1; i < n-1; i += 2) {
		int last = i == 1? 0: pre1[j-1];
		if (a[i] > a[i-1] && a[i] > a[i+1]) pre1.push_back(last);
		else pre1.push_back(last + max(a[i-1], a[i+1]) - a[i] + 1);
		j++;
	}
	j = 0;
	for (int i = 2; i < n-1; i += 2) {
		int last = i == 2? 0: pre2[j-1];
		if (a[i] > a[i-1] && a[i] > a[i+1]) pre2.push_back(last);
		else pre2.push_back(last + max(a[i-1], a[i+1]) - a[i] + 1);
		j++;
	}
	// for (int i: pre1) cerr << i << " ";
	// cerr << endl;
	// for (int i: pre2) cerr << i << " ";
	// cerr << endl;
	if (pre1.size() > pre2.size()) {
		cout << pre1.back() << endl;
	} else if (pre2.size() > pre1.size()) {
		cout << pre2.back() << endl;
	} else {
		// cout << " ";
		// cerr << pre1.back() << " " << pre2.back() << endl;
		int mn = pre2.back();
		for (int i = 0; i < pre1.size(); i++) {
			ckmin(mn, pre1[i] + pre2.back() - pre2[i]);
		}
		cout << mn << endl;
	}
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