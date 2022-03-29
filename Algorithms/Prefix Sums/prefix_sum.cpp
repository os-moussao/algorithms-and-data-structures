// https://darrenyao.com/usacobook/cpp.pdf#page=60
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

#define int long long
#define double long double

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;

#define REP(i, a, n) for(int i = a; i < n; i++)
#define SZ size()
#define LN length()
#define F first
#define S second
#define PB push_back
#define PF push_front
#define B begin()
#define E end()
#define nn '\n'
#define ss ' '

const int MOD = 1e9 + 7;

// sum range
int sumRg(int s, int e, vi &prefix)
{
	if (s == 0)
		return (prefix[e]);
	return (prefix[e] - prefix[s  -1]);
}

int32_t main()
{
	vi A{2, 1, 4, 5, 3, 7, 8};
	vi S(A.SZ);

	S[0] = A[0];
	REP(i, 1, A.SZ)
		S[i] = A[i] + S[i - 1];

	cout << sumRg(0, 5, S) << nn;
	cout << sumRg(1, 5, S) << nn;
	cout << sumRg(2, 4, S) << nn;
}
