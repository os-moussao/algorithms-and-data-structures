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
	vector <string> g(n);
	for (string &s: g) cin >> s;
	int nn = (n+1)/2;
	int ans = 0;
	for (int d = 0; d < nn; d++) {
		int s = d, e = n-1-d;
		vector <string> k(4);
		for (int i = e; i >= s; i--) {
			k[0] += g[s][i];
		}
		for (int i = s; i <= e; i++) {
			k[1] += g[i][s];
		}
		for (int i = s; i <= e; i++) {
			k[2] += g[e][i];
		}
		for (int i = e; i >= s; i--) {
			k[3] += g[i][e];
		}
		// for (int i = 0; i < 4; i++) {
		// 	cerr << k[i] << endl;
		// }
		for (int i = 0; i < e-s; i++) {
			int o = 0, z = 0;
			for (int j = 0; j < 4; j++) {
				o += (k[j][i] == '1');
				z += (k[j][i] == '0');
			}
			ans += min(o, z);
		}
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