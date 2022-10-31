#include <bits/stdc++.h>
#include <testlib.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

int32_t main(int32_t ac, char ** av) {
	registerGen(ac, av, 1);
	for (int i = 0; i < 20; i++) {
		ofstream test_file("testdir/test_" + to_string(i));
		int n = rnd.next(i < 10? 1: 10000, i < 10? 1000: 100000), q = rnd.next(i < 10? 1: 10000, i < 10? 1000: 100000);
		test_file << n << ' ' << q << endl;
		for (int i = 0; i < n; i++) {
			test_file << rnd.next(1LL, (int)(1e9)) << ' ';
		}
		test_file << endl;
		for (int i = 0; i < q; i++) {
			test_file << rnd.next(1LL, (int)(1e4)) << endl;
		}
		test_file.close();
	}
	ofstream test_file("testdir/test_20");
	test_file << (int)1e5 << ' ' << (int)1e5 << endl;
	for (int i = 0; i < 1e5; i++) {
		test_file << (int)1e9 - 1 << ' ';
	}
	test_file << endl;
	for (int i = 0; i < 1e5; i++) {
		test_file << (int)1e4 - 1 << endl;
	}
	test_file.close();
	ofstream test_file2("testdir/test_21");
	test_file2 << (int)1e5 << ' ' << (int)1e5 << endl;
	for (int i = 0; i < 1e5; i++) {
		test_file2  << (int)1e9 << ' ';
	}
	test_file2 << endl;
	for (int i = 0; i < 1e5; i++) {
		test_file2 << (int)1e4 << endl;
	}
	test_file2.close();
}