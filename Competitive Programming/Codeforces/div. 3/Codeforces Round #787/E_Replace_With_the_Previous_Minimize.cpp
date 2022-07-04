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

class DSU {
	public:
		int n;
		vector <int> par;
		vector <int> sz;
		vector <int> mn;
		int cnt;
		DSU(){}
		DSU(int N) {
			n = cnt = N;
			par.resize(n); sz.resize(n); mn.resize(n);
			while (N--) {
				par[N] = N;
				sz[N] = 1;
				mn[N] = N;
			}
		}
		int find(int p) {
			return par[p] == p? p: par[p] = find(par[p]);
		}
		bool connected(int p, int q) {
			return find(p) == find(q);
		}
		int size(int p) {
			return sz[find(p)];
		}
		bool join(int p, int q) {
			int root1 = find(p);
			int root2 = find(q);
			if (root1 == root2) return 0;
			if (sz[root1] < sz[root2]) swap(root1, root2);
			par[root2] = root1;
			sz[root1] += sz[root2];
			ckmin(mn[root1], mn[root2]);
			cnt--;
			return 1;
		}
};


void solve()
{
	int n, k; cin >> n >> k;
	string s;
	cin >> s;
	DSU dsu(26);
	for (int i = 0; i < n; i++) {
		if (!k) break ;
		int need=0, l = s[i]-'a';
		while (l > 0 && dsu.size(l) == 1) l--, need++; 
		need = min(k, need);
		k -= need;
		for (int ii = s[i]-'a'; ii >= s[i]-need-'a'; ii--) {
			dsu.join(ii, s[i]-'a');
		}
	}
	for (int i = 0; i < n; i++) {
		cout << (char)(dsu.mn[dsu.find(s[i]-'a')] + 'a');
	}
	cout << endl;
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