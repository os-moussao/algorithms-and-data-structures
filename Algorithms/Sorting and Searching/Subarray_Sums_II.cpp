// https://cses.fi/problemset/task/1661/
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

int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, x; cin >> n >> x;
	vi pre(n+1); pre[0] = 0;
	map <int, int> mp; mp[0]++;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		cin >> pre[i];
		pre[i] += pre[i-1];
		ans += mp[pre[i]-x];
		mp[pre[i]]++;
	}
	cout << ans << endl;
}