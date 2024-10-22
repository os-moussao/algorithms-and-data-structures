// Modular Arithmetic
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
int inv(int a) { return power(a, MOD-2); }
int addMod(int a, int b) { return ((a%MOD + b%MOD) % MOD + MOD) % MOD; }
int subMod(int a, int b) { return addMod(a, -b); }
int multMod(int a, int b) { return ((a%MOD * b%MOD) % MOD + MOD) % MOD; }
int divMod(int a, int b) { return multMod(a, inv(b)); }

// Sieve
bitset<(int)1e6> SIEVE;
void preSieve() {
  SIEVE[0]=SIEVE[1]=1;
  for (int i = 2; i*i < 1e6; i++) {
    if (!SIEVE[i]) {
      for (int j=i*i; j < 1e6; j+=i) {
        SIEVE[j]=1;
      }
    }
  }
}

// Prime factorization
vector<int> v(1e7+1); // v[i] = smallest prime factor of i
void prePrimeFact() {
  for (int i = 0; i <= 1e7; i++) v[i] = i;
  for (int i = 2; i <= 1e7; i++) {
    if (v[i] != i) continue ;
    for (int j = i*i; j <= 1e7; j += i) {
      if (v[j]==j) v[j] = i;
    }
  }
}
vector<int> primeFact(int n) { // with precalc - O(log)
  vector<int> fct;
  while (n != 1) {
    int i = v[n];
    while (n % i == 0)
      n /= i;
    fct.push_back(i);
  }
  return fct;
}
vector<int> prime_fact(int n) { // without precalc - O(sqrt)
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

// Factorial and Binomial Coefficient (n choose k)
const int MAXN = 2e5 + 5;
int fact[MAXN], ifact[MAXN];
void preFact() {
  fact[0] = ifact[0] = 1;
  for (int i = 1; i < MAXN; i++) {
    fact[i] = (fact[i-1] * i) % MOD;
    ifact[i] = (ifact[i-1] * inv(i)) % MOD;
  }
}
int nCk(int n, int k) { // (n choose k)
  return k > n? 0: (fact[n] * ((ifact[n-k] * ifact[k]) % MOD)) % MOD;
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
int PHI[MAXN];
void prePhi() {
  for (int i=0; i < MAXN; i++) PHI[i] = i;
  for (int i = 2; i < MAXN; i++) {
    if (PHI[i] == i) {
      for (int j = i; j < MAXN; j += i) {
       PHI[j] -= PHI[j] / i;
      }
    }
  }
}

int inv(int a, int m) {
  return power(a, PHI[m]-1, m); // or phi(m)-1 depends if m is big or no !
}
