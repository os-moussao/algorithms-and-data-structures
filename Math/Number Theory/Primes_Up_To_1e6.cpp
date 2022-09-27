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
