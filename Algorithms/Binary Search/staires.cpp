// https://arena.moi/problem/jnjd2020stairs
// you have virtually participate to see the problem statement
// contest: https://arena.moi/contest/jnjd2021practice
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

int good(int n, int h) {
	int lo = h, hi = n, mid;
	while (lo <= hi) {
		mid = lo+(hi-lo)/2;
		int sol = (mid-h+1)*h+((mid-h)*(mid-h+1))/2;
		if (sol == n) {
			return mid;
		}
		else if (sol < n) {
			lo = mid + 1;
		}
		else {
			hi = mid - 1;
		}
	}
	return 0;
}

vector<int> sum;

void preproc() {
	int s = 0;
	for (int i = 0; ; i++) {
		s += i;
		if (s > 1e8) break ;
		sum.push_back(s);
	}
}

signed main() {
	preproc();
	int x; cin >> x;
	int lo = 0, hi = sum.size() - 1, mid, ind;
	while (lo <= hi) {
		mid = lo + (hi - lo) / 2;
		if (sum[mid] <= x) {
			ind = mid;
			lo = mid + 1;
		}
		else {
			hi = mid - 1;
		}
	}
	while (ind >= 0) {
		if ((x-sum[ind])%(ind+1) == 0) {
			int f = ind + 1;
			int h1 = (x - sum[ind]) / f;
			int h2 = h1 + ind;
			cout << h1+!h1 << " " << h2 << endl;
			break ;
		}
		ind--;
	}
}
