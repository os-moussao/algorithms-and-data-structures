#pragma once

const int MOD = (1e9 + 7);

int power(int a, int b, int c=MOD) {
	int res = 1;
	a %= MOD;
	while (b) {
		if (b&1) res = (res * a) % MOD;
		a = (a * a) % MOD;
		b >>= 1;
	}
	return res;
}

int inv(int a) {
	return power(a, MOD-2);
}

const int MAXN = 2e5 + 5;
int fact[MAXN], ifact[MAXN];
void preFact() {
	fact[0] = ifact[0] = 1;
	for (int i = 1; i < MAXN; i++) {
		fact[i] = (fact[i-1] * i) % MOD;
		ifact[i] = (ifact[i-1] * inv(i)) % MOD;
	}
}

int nCk(int n, int k) {
	return k > n? 0: (fact[n] * ((ifact[n-k] * ifact[k]) % MOD)) % MOD;
}

// Prime factorization
vector<int> prime_fact(int n) {
	vector<int> ret;
	for (int i = 2; i*i <= n; i++) {
		if (n%i == 0) {
			ret.push_back(i);
			while (n%i == 0)
				n /= i;
		}
	}
	if (n > 1) ret.push_back(n);
	return ret;
}

// Euler's totient function
// a^phi(m) = 1 [modulo m] if a and m are coprimes
int phi(int x) {
	int res = x;
	for (int i = 2; i*i <= x; i++) {
		if (x%i == 0) {
			while (x%i == 0) x /= i;
			res -= res / i;
		}
	}
	if (x > 1) res -= res / x;
	return res;
}

// phi preprocessing from 1 to n
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