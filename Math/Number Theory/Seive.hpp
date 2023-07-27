#pragma once

bitset<(int)1e6> seive;
vector<int> primes;
void pre() {
	seive[0]=seive[1]=1;
	for (int i = 2; i*i < 1e6; i++) {
		if (!seive[i]) {
			for (int j=i*i; j < 1e6; j+=i) {
				seive[j]=1;
			}
		}
	}
	for (int i= 2; i< 1e6; i++) {
	    if (!seive[i]) primes.push_back(i);
	}
}

// v[i] = smallest prime factor of i
vector<int> v(1e7+1);
void fun() {
	for (int i = 0; i <= 1e7; i++) v[i] = i;
	for (int i = 2; i <= 1e7; i++) {
		if (v[i] != i) continue ;
		for (int j = i*i; j <= 1e7; j += i) {
			if (v[j]==j) v[j] = i;
		}
	}
}

// prime fact using smallest factor vector
vector<int> prime_fact(int n) {
	vector<int> fct;
	while (n != 1) {
		int i = v[n];
		while (n % i == 0)
			n /= i;
		fct.push_back(i);
	}
	return fct;
}