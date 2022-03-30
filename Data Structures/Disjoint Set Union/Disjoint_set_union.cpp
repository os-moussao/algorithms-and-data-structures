#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <map>

using namespace std;

class DSU {

public:
	// The number of elements in this disjoint set
	int N = 0;

	// The number of components in this DSU
	int cnt = 0;

	// par[i] points to the parent of i, if par[i] == i then i is a root node
	vector <int> par;

	// The sizes of the components
	vector <int> sz;

	// The ranks
	vector <int> rnk;

	// constructor
	DSU(){N=0; cnt=0;}
	DSU(int n) {
		N = n;
		cnt = n;
		par.resize(n);
		sz.resize(n);
		rnk.resize(n);
		for (int i = 0; i < n; i++) {
			par[i] = i;
			sz[i] = 1;
			rnk[i] = 0;
		}
	}

	int makeSet(void) {
		N++;
		cnt++;
		par.push_back(N - 1);
		sz.push_back(1);
		rnk.push_back(0);
		return N - 1;
	}

	// FIND
	// find which component/set p belongs to.
	int find(int p) {
		stack <int> S;

		// Find root of the component and save the path
		while (par[p] != p)
		{
			S.push(p);
			p = par[p];
		}

		// Path compression
		while (!S.empty()) {
			par[S.top()] = p;
			S.pop();
		}
		
		return p;
	}

	// FIND
	// another iterative method
	int find_it(int p)
	{
		int root = p;
		while (par[root] != root)
			root = par[root];

		while (p != root) {
			int next = par[p];
			par[p] = root;
			p = next;
		}

		return root;
	}

	// FIND recursive
	int find_rc(int p) {
		return (p == par[p]? p: par[p] = find(par[p]));
	}

	bool connected(int p, int q) {
		return find(p) == find(q);
	}

	int csize(int p) {
		return sz[find(p)];
	}

	// UNIFY
	bool unify(int p, int q)
	{
		int root1 = find(p);
		int root2 = find(q);

		if (root1 == root2) return false;

		if (sz[root2] > sz[root1]) swap(root1, root2);
		sz[root1] += sz[root2];
		par[root2] = root1;

		cnt--;

		return true;
	}

	// Unify by rank
	bool unify_by_rnk(int p, int q)
	{
		int root1 = find(p);
		int root2 = find(q);

		if (root1 == root2) return 0;

		if (rnk[root2] > rnk[root1]) swap(root1, root2);
		
		par[root2] = root1;
		sz[root1] += sz[root2];

		if (rnk[root1] == rnk[root2])
			rnk[root1]++;

		cnt--;

		return 1;
	}

	// print dsu
	void print(void) {
		cout << "Number of elements: " << N << "\nNumber of sets: " << cnt << '\n';
		cout << "Roots[]:   ";
		for (int i = 0; i < N; i++) {
			cout << find(i) << ' ';
		}
		cout << "\nSizes[]:   ";
		for (int i = 0; i < N; i++) {
			cout << csize(i) << ' ';
		}
		cout << "\nRanks[]:   ";
		for (int i = 0; i < N; i++) {
			cout << rnk[i] << ' ';
		}
		cout << "\nParents[]: ";
		for (int i = 0; i < N; i++) {
			cout << par[i] << ' ';
		}
	}
};

int main()
{
	cout << "==================== Test 1: unify ========================\n";
	DSU dsu = DSU(7);

	dsu.unify(0, 1);
	dsu.unify(1, 2);
	dsu.unify(3, 4);
	dsu.unify(5, 6);
	dsu.unify(4, 5);
	dsu.unify(2, 6);

	dsu.print();

	cout << "\n================== Test 2: unify by rank ===================\n";
	dsu = DSU(7);

	dsu.unify_by_rnk(0, 1);
	dsu.unify_by_rnk(1, 2);
	dsu.unify_by_rnk(3, 4);
	dsu.unify_by_rnk(5, 6);
	dsu.unify_by_rnk(4, 5);
	dsu.unify_by_rnk(2, 6);

	dsu.print();
}

// My DSU template for cp
/*
class DSU {
public:
	int N = 0;
	int cnt = 0;
	vector <int> par;
	vector <int> sz;
	vector <int> rnk;
	DSU(){N=0; cnt=0;}
	DSU(int n) {
		N = cnt = n;
		par.resize(n);  sz.resize(n);  rnk.resize(n);
		for (int i = 0; i < n; i++) {
			par[i] = i; sz[i] = 1; rnk[i] = 0;
		}
	}
	int find(int p) {
		return (p == par[p]? p: par[p] = find(par[p]));
	}
	bool connected(int p, int q) {
		return find(p) == find(q);
	}
	int size(int p) {
		return sz[find(p)];
	}
	bool unify(int p, int q)
	{
		int root1 = find(p);
		int root2 = find(q);
		if (root1 == root2) return 0;
		if (rnk[root2] > rnk[root1]) swap(root1, root2);
		par[root2] = root1;
		sz[root1] += sz[root2];
		if (rnk[root1] == rnk[root2])  rnk[root1]++;
		cnt--;
		return 1;
	}
};
*/