// task: https://www.codechef.com/problems/COPRIME3
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define SZ(x) ((int)(x.size()))
#define endl '\n'
	
#define MX 1000005

int prime_fact[MX];
int multiples[MX];
void init() {
	for (int i = 2; i < MX; i++) {
		if (!prime_fact[i]) {
			for (int j = i; j < MX; j += i) {
				prime_fact[j]=i;
			}
		}
	}
}

vector<int> get(int n) {
	vector<int> pf;
	while (n!=1) {
		int p = prime_fact[n];
		pf.push_back(p);
		while (n%p == 0)
			n /= p;
	}
	return pf;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	init();
	int n; cin >> n;
	vector <int> a(n);
	vector<vector<int>> prf(n);
	for (int id= 0; id< n; id++) {
		cin >> a[id];
		int &i = a[id];
		prf[id]=get(i);
		vector<int> &pf = prf[id];
		i=1;
		for (int p: pf) i *= p;
		multiples[1]++;
		for (int k = 1; k < (1 << SZ(pf)); k++) {
			int x = 1;
			for (int j = 0; j < SZ(pf); j++) {
				if (k & (1 << j)) {
					x *= pf[j];
				}
			}
			multiples[x]++;
		}
	}
	int ans = 0;
	for (int id=0; id < n; id++) {
		int i=a[id];
		vector<int> &pf =prf[id];
		int loc = 0;
		for (int k=1; k < (1 << SZ(pf)); k++) {
			int p = 1, sz=0;
			for (int j = 0; j < SZ(pf); j++) {
				if (k&(1 << j)) {
					p *= pf[j], sz++;
				}
			}
			int bad = ((multiples[p]-1)*(multiples[p]-2))/2;
			if (sz&1) loc+=bad;
			else loc -= bad;
		}
		ans += ((n-1)*(n-2))/2 - loc;
	}
	cout << ans/3 << endl;
}