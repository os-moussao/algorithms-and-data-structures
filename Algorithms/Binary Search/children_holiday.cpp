// problem link: https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/D
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

struct at {
	int t;
	int x;
	int y;
};

int m, n;
vector <at> arr;

bool can(int time) {
	int gen = 0;
	for (at &e: arr) {
		int xtime = e.x * e.t + e.y;
		gen += (time/xtime)*e.x + min(e.x, (time%xtime)/e.t);
	}
	return gen >= m;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> m >> n;
	arr = vector<at>(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i].t >> arr[i].x >> arr[i].y;
	}
	int lo = 0, hi = (int)1e12, mid, ans;
	while (lo <= hi) {
		mid = lo+(hi-lo)/2;
		if (can(mid)) {
			ans = mid;
			hi = mid - 1;
		}
		else {
			lo = mid + 1;
		}
	}
	cout << ans << endl;
	int gen = 0;
	for (at &e: arr) {
		int xtime = e.x * e.t + e.y;
		int greedy = min((ans/xtime)*e.x + min(e.x, (ans%xtime)/e.t), m - gen);
		cout << greedy << " ";
		gen += greedy;
	}
}