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
 
namespace macros {
 
using namespace std;
 
#define int long long
#define double long double
 
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef pair<double, double> pdd;
typedef pair<char, int> pci;
typedef vector<pci> vpci;
 
#define REP(i, a, n) for(int i = a; i < n; i++)
#define FOR(i, n) for(int i = 0; i < n; i++)
#define RREP(i, n, a) for(int i = n; i >= a; i--)
#define RFOR(i, n) for(int i = n; i >= 0; i--)
#define ITER(i, a, b) for(auto i = a; i != b; i++)
#define SZ size()
#define L length()
#define F first
#define S second
#define MP(x, y) make_pair(x, y)
#define PB push_back
#define PF push_front
#define B begin()
#define RB rbegin()
#define E end()
#define RE rend()
#define ALL(a) a.B, a.E
#define RALL(a) a.RB, a.RE
#define nn '\n'
#define ss ' '
#define YESORNO(x) cout << (x? "YES\n": "NO\n")
#define MAXVEC(vec) *max_element(ALL(vec))
#define MINVEC(vec) *min_element(ALL(vec))
#define getunique(vec)  {sort(vec.begin(), vec.end()); vec.erase(unique(vec.begin(), vec.end()), vec.end());}
 
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef LOCAL
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
} using namespace macros;
void    setIO(string s);

const int mod = 1e9 + 7;
 
class Graph {
public:
	vector<vector<int>> adj;
	Graph(){};
	Graph(int n) {
		adj.resize(n);
	}
	void edge(int u, int v) {
		adj[u].push_back(v);
	}
	void uedge(int u, int v) {
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
};
 
int  n, m, s, t;
Graph g;
vi dist;
vi dp[2];

void sum(int &a, int b) {
	a = (a + b) % mod;
}

int run_dp_1(int tar) {
	if (dp[0][tar] != -1) return dp[0][tar];

	dp[0][tar] = 0;
	for (int u: g.adj[tar]) {
		if (dist[u] == dist[tar] - 1) {
			sum(dp[0][tar], run_dp_1(u));
		}
	}
	return dp[0][tar];
}

int run_dp_2(int tar) {
	if (dp[1][tar] != -1) return dp[1][tar];

	dp[1][tar] = 0;
	for (int u: g.adj[tar]) {
		if (dist[u] == dist[tar])
			sum(dp[1][tar], run_dp_1(u));
		else if (dist[u] == dist[tar] - 1)
			sum(dp[1][tar], run_dp_2(u));
	}
	return dp[1][tar];
}

int bfs_mn_p()
{
	vb vis(n, 0);
	queue <int> Q;

	Q.push(s);
	vis[s] = 1;
	while (!Q.empty())
	{
		int v = Q.front(); Q.pop();

		for (int u: g.adj[v]) {
			if (!vis[u]) {
				Q.push(u);
				vis[u] = 1;
				dist[u] = dist[v] + 1;
			}
		}
	}
	return dist[t];
}

void solve()
{
	cin >> n >> m >> s >> t;
	--s, --t;
	g = Graph(n);
	FOR (i, m) {
		int x, y; cin >> x >> y;
		--x, --y;
		g.uedge(x, y);
	}
	dp[0] = vi(n, -1);
	dp[1] = vi(n, -1);
	dp[0][s] = 1;
	dp[1][s] = 0;
	dist = vi(n, 0);
	bfs_mn_p();
	cout << (run_dp_1(t) + run_dp_2(t)) % mod << nn;
}

void preprocessing() {}

bool MULTY_TEST_CASES = 1;
 
int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << setprecision(20);
	cout << fixed;
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
	// setIO("");
 
	preprocessing();
 
	int t = 1;
	if (MULTY_TEST_CASES) cin >> t;
 
	while (t--) {
		solve();
	}
	return 0;
}
 
void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}