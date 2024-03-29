#pragma once

const int MOD = (1e9 + 7);

int power(int a, int b, int c=MOD) {
	int res = 1;
	a %= c;
	while (b) {
		if (b&1) res = (res * a) % c;
		a = (a * a) % c;
		b >>= 1;
	}
	return res;
}

int inv(int a) {
	return power(a, MOD-2);
}

int addMod(int a, int b) {
	return ((a%MOD + b%MOD) % MOD + MOD) % MOD;
}

int subMod(int a, int b) {
	return addMod(a, -b);
}

int multMod(int a, int b) {
	return ((a%MOD * b%MOD) % MOD + MOD) % MOD;
}

int divMod(int a, int b) {
	return multMod(a, inv(b));
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

int inv(int a, int m) {
	return power(a, phi[m]-1, m); // or phi(m)-1 depends if m is big or no !
}
