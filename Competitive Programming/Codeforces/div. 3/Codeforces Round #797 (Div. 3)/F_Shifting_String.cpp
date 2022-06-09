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

int gcd(int a, int b) {
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int lcm(int a, int b) {
	return ((a*b)/gcd(a,b));
}

void solve()
{
	int n; cin >> n;
	string s; cin >> s;
	int par[n];
	bool vis[n]; memset(vis, 0, sizeof vis);
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		par[--x] = i;
	}
	auto process = [&](int x) {
		string tmp;
		stack <char> stak;
		vis[x] = 1;
		int y = par[x];
		while (y != x) {
			vis[y] = 1;
			stak.push(s[y]);
			y = par[y];
		}
		tmp += s[x];
		while (!stak.empty()) {
			tmp += stak.top(); stak.pop();
		}
		for (int i = 1; i < tmp.size(); i++) {
			string ss; ss.resize(tmp.size());
			for (int j = 0; j < tmp.size(); j++) {
				ss[j] = tmp[(j+i)%tmp.size()];
			}
			if (ss == tmp) {
				return i;
			}
		}
		return (int)tmp.size();
	};
	vector <int> lst;
	for (int i = 0; i < n; i++) {
		if (!vis[i]) {
			lst.push_back(process(i));
		}
	}
	int ans = lst[0];
	for (int i = 1; i < lst.size(); i++) ans = lcm(ans, lst[i]);
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