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

// sum 2d range
int sum2dRg(pi s, pi e, vvi &sums)
{
	if (s.F == s.S == 0)
		return (sums[e.F][e.S]);
	return (sums[e.F][e.S] - sums[s.F - 1][e.S] - sums[e.F][s.S - 1]
		   	+ sums[s.F - 1][s.S - 1]);
}

int32_t main()
{
	vvi A {
		{1, 5, 6, 11, 8},
		{1, 7, 11, 9, 4},
		{4, 6, 1, 3, 2},
		{7, 5, 4, 2, 3}
	};

	vvi S(4, vi(5));
	
	S[0][0] = A[0][0];

	REP(j, 1, S[0].SZ)
		S[0][j] = S[0][j - 1] + A[0][j];
	REP(i, 1, S.SZ)
		S[i][0] = S[i - 1][0] + A[i][0];
	REP(i, 1, S.SZ)
		REP(j, 1, S[0].SZ)
			S[i][j] = S[i - 1][j] + S[i][j - 1] - S[i - 1][j - 1] + A[i][j];
	
	cout << sum2dRg({1, 1}, {2, 3}, S) << nn;
}
