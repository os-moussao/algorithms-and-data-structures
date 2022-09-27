// Used: 686 ms, 123 MB in codeforces custom test
bitset<(int)1e8> seive;
vector<int> primes;
int sz=0; // 1229 prime numbers under 1e8

void pre() {
	seive[0]=seive[1]=1;
	for (int i = 2; i*i < 1e8; i++) {
		if (!seive[i]) {
			primes.push_back(i);
			sz++;
			for (int j=i*i; j < 1e8; j+=i) {
				seive[j]=1;
			}
		}
	}
}