#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cstdint>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <deque>

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

template<class T> bool ckmin(T& a, const T b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T b) { return a < b ? a = b, 1 : 0; }
template<class T> bool ft_swap(T &mn, T &mx) {return mn > mx? (swap(mn, mx), 1): 0;}

int good(vi &pre, int x, int m) {
    int n = (int)pre.size();
    int mx = 0;
    for (int i = x; i < n; i++) {
        ckmax(mx, pre[i]-pre[i-x]);
    }
    return mx >= m;
}

void solve()
{
	int n, m; cin >> n >> m;
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vi pre(n+1); pre[0] = 0;
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i-1] + a[i-1];
    }
    map <int, int> h;
    int mx = -1;
    for (int i = 1; i <= n; i++) {
        // cerr << i <<  " #\n";
        if (pre[i] && !h[pre[i]]) {
            h[pre[i]] = i;
        }
        int need = (pre[i] - m);
        if (need < 0) continue;
        else if (need == 0) {
            ckmax(mx, i);
        }
        else {
            int ii = h[need];
            if (ii) {
                ckmax(mx, i-ii);
                // cerr << i << endl;
                // cerr << need << endl;
                // cerr << ii << endl;
                // cerr << i-ii << endl;
            }
        }
    }
    cout << ((mx == -1)? -1: n-mx) << endl;
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