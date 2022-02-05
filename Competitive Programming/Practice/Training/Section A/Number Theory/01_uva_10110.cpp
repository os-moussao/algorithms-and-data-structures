#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <stdbool.h>

using namespace std;

#define int long long
#define double long double

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<char, int> pci;
typedef vector<pii> vpii;
typedef vector<pdd> vpdd;
typedef vector<pci> vpci;

#define REP(i, a, n) for(int i = a; i < n; i++)
#define FOR(i, n) for(int i = 0; i < n; i++)
#define RREP(i, n, a) for(int i = n; i >= a; i--)
#define RFOR(i, n) for(int i = n; i >= 0; i--)
#define ITER(i, a, b) for(auto i = a; i != b; i++)
#define SZ size()
#define L length()
#define F first
#define S second
#define PB push_back
#define PF push_front
#define B begin()
#define E end()
#define nn '\n'
#define ss ' '

bool is_prime(int n) {
	int sq = sqrt(n);
	if (n <= 1) {
		return 0;
	}
	for (int i = 2; i <= sq; i++) {
		if (!(n % i)) {
			return 0;
		}
	}
	return 1;
}

int32_t main()
{
	int t;

	cin >> t;
	while (t--) {
		int n; cin >> n;
		cout << (( is_prime(n)? "yes": "no")) << nn;
	}
	return 0;
}
