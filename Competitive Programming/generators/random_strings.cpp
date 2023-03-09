#include <bits/stdc++.h>
#include <testlib.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

int32_t main(int32_t ac, char ** av) {
	registerGen(ac, av, 1);
	for (int i = 0; i < 50; i++) {
		ofstream test_file("testdir/test_" + to_string(i));
		int n;
		if (i <= 10) n = rnd.next(10,100);
		else if (i < 49) n = rnd.next(500,1000-1);
		else n = 1000;
		vector<string> a(n);
		for (int i = 0; i < n; i++) {
			int rep = rnd.next(1, 50), ln = 0;
			string s = rnd.next("[a-z]{10}");
			for (int j = i; rep && j < n; j++) {
				ln++, rep--;
				a[j] = s;
			}
			i += ln-1;
		}
		shuffle(a.begin(),a.end());
		test_file << n << endl;
		for (string &s: a) {
			test_file << s << endl;
		}
	}
}