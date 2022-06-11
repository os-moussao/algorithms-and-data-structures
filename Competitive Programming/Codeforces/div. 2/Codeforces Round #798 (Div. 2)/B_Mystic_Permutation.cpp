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
	int n; cin >> n;
    vi p(n+1);
    for (int i = 0; i < n; i++) cin >> p[i];
    if (n == 1) {
        cout << -1 <<endl;
        return;
    }
    if (n == 2) {
        swap(p[0], p[1]);
        cout << p[0] << " " << p[1] << endl;
        return ;
    }
    vector<int> h(n+1, 0); 
    vi q(n+1);
    for (int i = 0; i < n-3; i++) {
        int mn = 1e9;
        for (int j = 0; j < n; j++) {
            if (h[p[j]] || p[j] == p[i]) continue;
            ckmin(mn, p[j]);
        }
        h[mn] = 1;
        q[i] = mn;
    }
    vi remain;
    for (int i = 1; i <= n; i++) {
        if (h[i]) continue;
        remain.push_back(i);
    }
    sort(ALL(remain));
    bool flag = 0;
    for (int i = 0; i < 6; i++) {
        q[n-3] = remain[0];
        q[n-2] = remain[1];
        q[n-1] = remain[2];
        bool ok = 1;
        for (int i = n-3; i < n; i++) {
            if (q[i] == p[i]) ok = 0;
        }
        if (ok) {
            for (int i = 0; i < n; i++) {
                cout << q[i] << " ";
            }
            cout << endl;
            return ;
        }
        next_permutation(ALL(remain));
    }
    cout << -1 << endl;
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