// link: https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/F
#include <bits/stdc++.h>

using namespace std;
#define int long long
#define endl '\n'

int n;
string s;
string p;
int del[(int)(2e5+5)];

bool can(int t) {
	int k = 0;
	int h[n];
	memset(h, 0, n*sizeof(int));
	for (int i = 0; i < t; i++) h[del[i]] = 1;
	for (int i = 0; i < n; i++) {
		if (h[i]) continue;
		k += (s[i] == p[k]);
		if (k == p.length()) break ;
	}
	return k == p.length();
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> s >> p;
	n = s.length();
	for (int i = 0; i < n; i++) {
		cin >> del[i]; --del[i];
	}
	int lo = 0, hi = n, ans, mid;
	while (lo <= hi) {
		mid = lo + (hi - lo) / 2;
		if (can(mid)) {
			lo = mid + 1;
			ans = mid;
		}
		else {
			hi = mid - 1;
		}
	}
	cout << ans << endl;
}
