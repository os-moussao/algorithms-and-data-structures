// link: https://codeforces.com/edu/course/2/lesson/6/3/practice/contest/285083/problem/C
#include <bits/stdc++.h>

using namespace std;
#define int long long 
#define double long double
#define endl '\n'

int n, k;
int arr[10010];

bool can(int dis) {
	int count = 1;
	int curr_pos = 0;
	while (count <= k) {
		int next_pos = lower_bound(arr, arr + n, arr[curr_pos] + dis) - arr;
		if (next_pos == n) {
			break ;
		}
		count++;
		curr_pos = next_pos;
	}
	return count >= k;
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int lo = 0, hi = arr[n - 1] - arr[0], ans, mid;
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