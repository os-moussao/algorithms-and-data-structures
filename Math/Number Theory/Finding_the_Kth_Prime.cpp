#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

vector <int> kthPrime;
bitset<90000000> seive;

void prep() {
	int index = 1;
	for (int i = 2; i*i < 9e7; i++) {
		if (!seive[i]) {
			for (int j = i*i; j < 9e7; j += i) {
				seive[j]=1;
			}
		}
	}
	kthPrime.push_back(-1);
	for (int i = 2; i < 9e7; i++) {
		if (!seive[i]) kthPrime.push_back(i);
	}
}

int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	prep();

	int t = 1;
	cin >> t;
	while (t--) {
		int n; cin >> n;
		cout << kthPrime[n] << endl;
	}
}