// link: https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/E
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define endl '\n'

double sqr(double x) {
	return x*x;
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	double c; cin >> c;
	double lo = 0, hi = c, mid, x = c, eps = 0.000001;
	// iterations: log2((R-L)/eps);
	// R-l = 1e10, eps = 1e-6, log2((R-L)/eps) = log2(1e16) = 53
	for (int i = 0; i < 60; i++) {
	// while (hi - lo > eps) {
		mid = lo + (hi - lo) / 2;
		double fx = sqr(mid) + sqrt(mid);
		if (fx >= c) {
			x = mid;
			hi = mid;
		}
		else {
			lo = mid;
		}
	}
	cout << fixed << setprecision(15) << x << endl;
}