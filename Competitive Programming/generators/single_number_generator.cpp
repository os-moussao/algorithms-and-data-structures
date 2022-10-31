#include <bits/stdc++.h>
#include <testlib.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

int32_t main(int32_t ac, char ** av) {
	registerGen(ac, av, 1);
	for (int i = 0; i < 40; i++) {
		ofstream test_file("testdir/test_" + to_string(i));
		test_file << rnd.next(i < 15? 2: (int)1e8, i < 15? (int)1e6: (int)1e12);
		test_file.close();
	}
	// primes
	vector<int> primes = {
		99990001, 99999677, 99999703, 99999721, 99999773, 99999787, 99999821, 99999827,
		99999839, 99999847, 99999931, 99999941, 99999959, 99999971, 99999989, 999999000001,
	};
	for (int p = 0, i = 40; p < primes.size(); p++, i++) {
		ofstream test_file("testdir/test_" + to_string(i));
		test_file << primes[p];
		test_file.close();
	}
}