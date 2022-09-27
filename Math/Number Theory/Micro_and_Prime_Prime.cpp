// task: https://www.hackerearth.com/practice/math/number-theory/primality-tests/practice-problems/algorithm/micro-and-prime-prime-1/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

int seive[(int)1e6 + 1], primes1n[(int)1e6 + 1], primePrime[(int)1e6 + 1];

void prep() {
	for (int &i: seive) i=1;
	seive[0]=seive[1]=0;
	for (int i = 2; i*i < 1e6 + 1; i++) {
		if (seive[i]) {
			for (int j = i*i; j < 1e6 + 1; j+=i) {
				seive[j]=0;
			}
		}
	}
	for (int i = 1; i < 1e6 + 1; i++) {
		primes1n[i] = primes1n[i-1] + seive[i];
	}
	for (int i = 1; i < 1e6 + 1; i++) {
		primePrime[i] = primePrime[i-1] + seive[primes1n[i]];
	}
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;

	prep();
	while (t--) {
		int l, r; cin >> l >> r;
		cout << primePrime[r]-primePrime[l-1] << endl;
	}
}