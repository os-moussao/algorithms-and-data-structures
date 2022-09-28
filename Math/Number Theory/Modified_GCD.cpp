// task: https://codeforces.com/contest/75/problem/C
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int a, b;
	cin >> a >> b;
	
	int _gcd = gcd(a, b);
	vector<int> div;
	for (int i = 1; i*i <= _gcd; i++) {
		if (_gcd % i == 0) {
			div.push_back(-i);
			if (_gcd/i != i) div.push_back(-_gcd/i);
		}
	}
	sort(div.begin(), div.end());
	
	int q; cin >> q;
	while (q--) {
		int l, r; cin >> l >> r;
		auto lb = lower_bound(div.begin(), div.end(), -r);
		if (lb == div.end() || -*lb < l) cout << -1 << endl;
		else {
			cout << -*lb << endl;
		}
	}
}