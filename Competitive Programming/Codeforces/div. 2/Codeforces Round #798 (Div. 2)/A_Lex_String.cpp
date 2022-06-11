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

void solve()
{
	int n, m, k; cin >> n >> m >> k;
    string a, b, c;
    cin >> a >> b;
    sort(ALL(a)); sort(ALL(b));
    // cerr << a << endl << b << endl;
    int ai = 0, bi = 0;
    int last = -1;
    while (ai < a.length() && bi < b.length()) {
        int kk = k;
        if (a[ai] < b[bi]) {
            if (last == 0) {
                c += b[bi++];
                last = 1;
                continue;
            }
            while (ai < a.length() && a[ai] < b[bi] && kk) {
                c += a[ai++];
                kk--;
            }
            last = 0;
        }
        else {
            if (last == 1) {
                last = 0;
                c += a[ai++];
                continue;
            }
            while (bi < b.length() && b[bi] < a[ai] && kk) {
                c += b[bi++];
                kk--;
            }
            last = 1;
        }
    }
    cout << c << endl;
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