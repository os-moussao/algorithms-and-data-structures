// https://codeforces.com/edu/course/2/lesson/6/3/practice/contest/285083/problem/B
#include <bits/stdc++.h>

using namespace std;
#define int long long 
#define double long double
#define endl '\n'

int n, k;
vector <int> arr;

bool can(int sum) {
	int count = 0;
	int s = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] > sum) return 0;
		if (s + arr[i] > sum) {
			s = arr[i];
			count++;
		}
		else {
			s += arr[i];
		}
	}
	count++;
	return count <= k;
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> k;
	int s = 0;
	arr.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		s += arr[i];
	}
	int lo = 0, hi = s, mid, ans;
	while (lo <= hi) {
		mid = lo + (hi - lo) / 2;
		if (can(mid)) {
			hi = mid - 1;
			ans = mid;
		}
		else {
			lo = mid + 1;
		}
	}
	cout << ans << endl;
}


/* I thought the problem asked for any possible groups, not continuous segments */
// sort(arr.rbegin(), arr.rend())
// bool can(int sum) {
// 	multiset <int> groups;
// 	for (int i = 0; i < n; i++) {
// 		if (arr[i] > sum) return 0;
// 		int need = sum - arr[i];
// 		auto it = groups.lower_bound(-need);
// 		if (it == groups.end()) {
// 			groups.insert(-arr[i]);
// 		}
// 		else {
// 			int new_val = *it - arr[i];
// 			groups.erase(it);
// 			groups.insert(new_val);
// 		}
// 	}
// 	return groups.size() <= k;
// }