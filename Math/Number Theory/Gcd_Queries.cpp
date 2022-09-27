// task: https://www.codechef.com/problems/GCDQ
#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
	    int n, q; cin >> n >> q;
	    int a[n];
	    for (int &i: a)  cin >> i;
	    int pre[n+1], suf[n+2];
	    pre[0]=suf[n+1]=0;
	    for (int i=1; i<=n; i++) pre[i] = gcd(pre[i-1], a[i-1]);
	    for (int i = n; i>= 1; i--) suf[i] = gcd(suf[i+1], a[i-1]);
	    while (q--) {
	        int l, r; cin >> l >> r;
	        int a = pre[l-1], b = suf[r+1];
	        cout << gcd(a, b) << '\n';
	    }
	}
}
