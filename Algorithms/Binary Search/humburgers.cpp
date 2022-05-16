// problem link: https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/H
#include <bits/stdc++.h>

using namespace std;
#define int long long
#define endl '\n'

int x, y, z, hv_x, hv_y, hv_z, price_x, price_y, price_z, r;

bool can(int n) {
	int need_x = max(x*n - hv_x, 0LL);
	int need_y = max(y*n - hv_y, 0LL);
	int need_z = max(z*n - hv_z, 0LL);
	int spend = need_x * price_x + need_y * price_y + need_z * price_z;
	return spend <= r;
}

int32_t main() {
	string str;
	cin >> str >> hv_x >> hv_y >> hv_z >> price_x >> price_y >> price_z >> r;
	x = y = z = 0;
	for (char ch: str) {
		x += ch == 'B';
		y += ch == 'S';
		z += ch == 'C';
	}
	int lo = 0, hi = 1e13, ans, mid;
	while (lo <= hi) {
		mid = lo + (hi - lo) / 2;
		if (can(mid)) {
			ans = mid;
			lo = mid + 1;
		}
		else {
			hi = mid - 1;
		}
	}
	cout << ans << endl;
}