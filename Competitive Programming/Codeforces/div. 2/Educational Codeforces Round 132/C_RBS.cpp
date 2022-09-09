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
#define popcount(x) __builtin_popcountll(x);

template<class T> bool ckmin(T& a, const T b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T b) { return a < b ? a = b, 1 : 0; }
template<class T> bool ft_swap(T &mn, T &mx) {return mn > mx? (swap(mn, mx), 1): 0;}

void solve()
{
	int n; string s;
	cin >> s; n = s.length();
	int op = n/2, cl = n/2;
	vi pos;
	for (int i = 0; i < n; i++) {
		char c = s[i];
		if (c == '(') op--;
		else if (c == ')') cl--;
		else {
			pos.push_back(i);
		}
	}
	// cerr << op << " " << cl << " ";
	if (!op || !cl) {
		// cerr << endl;
		cout << "YES" << endl;
		return ;
	}
	for (int p = 0; p < op - 1; p++) {
		s[pos[p]] = '(';
	}
	s[pos[op-1]] = ')';
	s[pos[op]] = '(';
	for (int p = op+1; p < pos.size(); p++) {
		s[pos[p]] = ')';
	}
	int x = 0;
	for (char c: s) {
		if (c == '(') x++;
		else x--;
		if (x < 0) {
			cout << "YES\n";
			return ;
		}
	}
	YESORNO(x);
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