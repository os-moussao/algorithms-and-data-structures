#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

const int MAXN = 1e6 + 5;
int phi[MAXN];
void prePhi() {
	for (int i=0; i < MAXN; i++) phi[i] = i;
	for (int i = 2; i < MAXN; i++) {
		if (phi[i] == i) {
			for (int j = i; j < MAXN; j += i) {
				phi[j] -= phi[j] / i;
			}
		}
	}
}
	
// fast sum of gcd's from 1 to n-1 with n
int sumOfGcds(int n) {
	int ans = 0;
	for (int i = 1; i*i <= n; i++) {
		if (n%i == 0) {
			ans += i * phi[n/i];
			if (n/i != i)
				ans += (n/i) * phi[i];
		}
	}
	return ans;
}

// brute force for checking
int sumGcdBF(int n) {
	int ans= 0;
	for (int i = 1; i<= n; i++) ans += gcd(i, n);
	return ans;
}

int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	prePhi();
	// takes about 6 seconds due to brute-force checking
	for (int i = 1; i < 10000; i++) {
		if (sumGcdBF(i) != sumOfGcds(i)) {
			cerr << "FAILS AT: " << i << endl;
			exit(1);
		}
	}
	cout << "SUCCESS\n";
}