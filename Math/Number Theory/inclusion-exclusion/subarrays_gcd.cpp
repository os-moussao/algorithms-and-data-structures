// task: https://codeforces.com/contest/1750/problem/D
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define SZ(x) (int)(x.size())

const int MOD = 998244353;
int m;

vector<pair<int, int>> prime_fact(int n) {
	vector<pair<int,int>> ret;
	for (int i = 2; i*i <= n; i++) {
		if (n%i == 0) {
			ret.push_back({i, 0});
			while (n%i == 0)
				n /= i, ret.back().second++;
		}
	}
	if (n > 1) ret.push_back({n, 1});
	return ret;
}

vector<pair<int, int>> prime_fact(int n, vector<pair<int, int>> &ipf) {
	vector<pair<int, int>> ret;
	for (pair<int, int> &p: ipf) {
		if (n % p.first == 0) {
			ret.push_back({p.first, 0});
			while (n % p.first == 0) {
				ret.back().second++;
				n /= p.first;
			}
		}
	}
	ipf=ret;
	return ret;
}

int eq(int x, int gc, vector<pair<int, int>> &ipf) {
	vector<pair<int, int>> fx = prime_fact(x, ipf);
	vector<pair<int, int>> pc = prime_fact(gc, ipf);
	vector<int> a;
	for (auto &[p, f]: fx) {
		int lo = 0, hi = SZ(pc)-1, pos = -1;
		while (lo <= hi) {
			int mid = lo+(hi-lo)/2;
			if (pc[mid].first==p) {
				pos=mid;
				break ;
			}
			if (pc[mid].first < p) lo=mid+1;
			else hi = mid-1;
		}
		if (pos==-1 || f!=pc[pos].second)
			a.push_back(p);
	}
	int all = m/gc;
	int bad = 0;
	for (int i = 1; i < (1 << SZ(a)); i++) {
		int x = gc, sz = 0;
		for (int j = 0; j < SZ(a); j++) {
			if (i & (1 << j)) {
				x *= a[j]; sz++;
			}
		}
		bad += sz&1? m/x: -m/x;
	}
	return all-bad;
}

void solve() {
	int n; cin >> n >> m;
	vector<int> a(n);
	for (int &i: a) cin>> i;
	for (int i = 1; i < n; i++) {
		if (a[i-1]%a[i] != 0) {
			cout << 0 << endl;
			return ;
		}
	}
	vector<pair<int, int>> ipf = prime_fact(a[0]);
	int ans = 1;
	for (int i = 1; i < n; i++) {
		ans *= a[i-1]==1? m%MOD: eq(a[i-1], a[i], ipf)%MOD;
		ans %= MOD;
	}
	cout << ans << endl;
}

int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t = 1;
	cin >> t;

	while (t--) {
		solve();
	}
}