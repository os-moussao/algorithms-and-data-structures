// task: https://www.codechef.com/problems/GCDMOD
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

const int MOD = 1e9 + 7;

int power(int a, int b, int c=MOD) {
	int res = 1;
	a %= c;
	while (b) {
		if (b&1) res = (res * a)%c;
		a = (a*a) % c;
		b >>= 1;
	}
	return res;
}

int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	cin >> t;

	while (t--) {
		int a, b, n;
		cin >> a >> b >> n;
		if (a < b) swap(a, b);
		// a^n + b^n gcd a-b
		int d = a-b;
		if (d==0) {
			cout << (power(a, n) + power(b, n)) % MOD << endl;
			continue;
		}
		vector<int> fact; // mx sz < sqrt(1e12) * 2 
		for (int i = 2; i*i <= d; i++) {
			if (d%i == 0) {
				fact.push_back(i);
				if (i != d/i) fact.push_back(d/i);
			}
		}
		fact.push_back(d);
		int gc = 1;
		for (int i = 0; i < fact.size(); i++) {
			if ((power(a, n, fact[i]) + power(b, n, fact[i])) % fact[i] == 0) {
				gc = max(gc, fact[i]);
			}
		}
		cout << gc << endl;
	}
}