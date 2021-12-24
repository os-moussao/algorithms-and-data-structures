#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <cmath>

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

vi segmentTree(vi &ar)
{
	int n = ar.SZ;
	vi tree(2*n);
	copy(ar.B, ar.E, tree.B + n);
	for (int i = n - 1; i > 0; i--)
		tree[i] = tree[2*i] + tree[2*i+1];
	return tree;
}

int	rangeSum(int l, int r, vi &tree)
{
	l += n; r += n;
	while (r < l)
	{

		r >>= 1;
		l >>= 1;
	}
}

int32_t main()
{
	vi ar{1, 2, 3, 4, 5, 6, 7, 8};
	vi tree = segmentTree(ar);
	for (int i = 0; i < 2*ar.SZ; i++)
		cout << tree[i] << ss;
	cout << nn;
}
