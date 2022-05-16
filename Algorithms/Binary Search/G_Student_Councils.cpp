// link: https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/G
#include <bits/stdc++.h>

using namespace std;
#define int long long
#define endl '\n'

int k, n;
int arr[55];

bool can(int teams) {
	int s = 0;
	for (int i = 0; i < n; i++) {
		s +=  min(teams, arr[i]);
	}
	return s/k >= teams;
}

int32_t main() {
	cin >> k >> n;
	int s = 0;
	for (int i = 0; i < n; i++) cin >> arr[i], s += arr[i];
	int lo = 0, hi = s/k, mid, ans;
	while (lo <= hi) {
		mid = lo + (hi - lo) / 2;
		if (can(mid)) {
			ans = mid, lo = mid + 1;
		}
		else {
			hi = mid - 1;
		}
	}
	cout << ans << endl;
}