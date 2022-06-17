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
	int n;
	cin >> n;
	vi a(n);
	for (int &i: a) cin >> i;
	while (!a.empty() && a.back() == 0) a.pop_back();
	if (a.size() <= 1) {
		cout << (a.empty()? "Yes": "No") << endl;
		return ;
	}
	if (a.back() > 0) {
		cout << "No" << endl;
		return ;
	}
	int bonus = 0;
	n = a.size();
	while (a.size() > 1) {
		int has_to_be = -a.back() - (n-2 == 0? 0: 1) + bonus;
		// cerr << n-2 << " " << has_to_be << " " << a.back() << endl;
		if (a[n-2] > has_to_be || n-2 == 0 && a[n-2] != has_to_be) {
			cout << "No" << endl;
			return ;
		}
		a.pop_back();
		a.back() = a.back() - has_to_be;
		bonus = 1;
		n--;
	}
	cout << "Yes" << endl;
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