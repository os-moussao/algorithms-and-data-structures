// link: https://codeforces.com/edu/course/2/lesson/6/3/practice/contest/285083/problem/A
#include <bits/stdc++.h>

using namespace std;
#define int long long 
#define double long double
#define endl '\n'

const double eps = 0.000001;

struct xv {
	double x, v;
};

int n;
vector <xv> arr;

bool can(double t) {
	// interval
	double l = arr[0].x - arr[0].v * t, r = arr[0].x + arr[0].v * t;
	for (int i = 1; i < n; i++) {
		// new interval
		double ll = arr[i].x - arr[i].v * t, rr = arr[i].x + arr[i].v * t;
		if (ll > r + eps || l > rr + eps) {
			return 0;
		}
		// get intersection
		l = max(l, ll);
		r = min(r, rr);
	}
	return 1;
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << setprecision(20);
	cout << fixed;

	cin >> n;
	arr.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i].x >> arr[i].v;
	}
	// sort(arr.begin(), arr.end(), [&](const xv &a, const xv &b) {return a.v < b.v;});
	// for (xv &s: arr) {
	// 	cerr << s.x << " " << s.v << endl;
	// }
	double lo = 0, hi = 1e9, ans, mid;
	for (int i = 0; i <= 60; i++) {
		mid = lo + (hi - lo) / 2;
		if (can(mid)) {
			hi = mid;
			ans = mid;
		}
		else {
			lo = mid;
		}
	}
	cout << ans << endl;
}