#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <cstdio>

using namespace std;
#define int long long
#define endl '\n'

vector <int> get_segtree(vector <int> &arr) {
	int n = arr.size();
	vector <int> tree;
	tree.resize(n*2);
	copy(arr.begin(), arr.end(), tree.begin() + n);
	for (int i = n - 1; i > 0; i--) {
		tree[i] = tree[i*2] + tree[i*2 + 1];
	}
	tree[0] = 0;
	return tree;
}

void update (vector <int> &segtree, int i, int new_val) {
	i += segtree.size() / 2;
	segtree[i] = new_val;
	while (i > 1) {
		i >>= 1;
		segtree[i] = segtree[i*2] + segtree[2*i+1];
	}
}

// (from and to inclusive)
int range_sum(vector <int> &segtree, int from, int to) {
	from += segtree.size() / 2;
	to += segtree.size() / 2;
	int sum = 0;
	while (from <= to) {
		if (from&1) { // if from is odd
			sum += segtree[from++];
		}
		if (!(to&1)) {
			sum += segtree[to--];
		}
		from >>= 1;
		to >>= 1;
	}
	return sum;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector <int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	vector <int> segtree = get_segtree(arr);
	// cerr << "segtree: ";
	// for (int i = 0; i < segtree.size(); i++) {
	// 	cerr << segtree[i] << " ";
	// }
	while (m--) {
		int q;
		cin >> q;
	
		// update query
		if (q == 1) {
			int index, new_val;
			cin >> index >> new_val;
			--index;
			update(segtree, index, new_val);
		}

		// get sum query
		else {
			int a, b;
			cin >> a >> b;
			--a, --b;
			cout << range_sum(segtree, a, b) << endl;
		}
	}
}
