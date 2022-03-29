// https://codeforces.com/gym/102644/problem/C
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

#define int long long
#define double long double

#define REP(i, n) for(int i = 0; i < n; i++)
#define nn '\n'
#define ss ' '

const int MOD = 1e9 + 7;

struct Matrix
{
	int a[2][2] = {{0, 0}, {0, 0}};

	Matrix operator *(const Matrix &other)
	{
		Matrix prod;
		REP(i, 2)REP(j, 2)REP(k, 2) {
			prod.a[i][j] += ((a[i][k] % MOD) * (other.a[k][j] % MOD)) % MOD;
			prod.a[i][j] %= MOD;
		};
		return prod;
	}
};

Matrix get_id(int n)
{
	Matrix I;
	REP(i, n) I.a[i][i] = 1;
	return (I);
}

Matrix pow(Matrix A, unsigned int n)
{
	Matrix res = get_id(2);
	while (n)
	{
		if (n&1) res = res * A;
		A = A * A;
		n >>= 1;
	}
	return res;
}

void solve()
{
	int n;
	cin >> n;

	if (n == 0) {
		cout << 0 << nn;
		return ; 
	}

	Matrix fib;
	fib.a[0][0] = 0;
	fib.a[0][1] = 1;
	fib.a[1][0] = 1;
	fib.a[1][1] = 1;
	
	fib = pow(fib, n - 1);

	cout << fib.a[1][1] << nn;
	
	/*
	 * if we notice that the matrix (0 1) is the first line of fib.a 
	 * (before raising to power of n)
	 * so we only need the
	fib = pow(fib, n);
	cout << fib.a[0][1] << nn;
	*/

	/*
	 * calc power then multiply by the matrix (0  1)
	
	fib = pow(fib, n - 1);
	int dp[1][2] = {{0, 1}};
	int res[1][2] = {{0, 0}};
	REP(i, 1)REP(j, 2)REP(k, 2){
		res[i][j] += dp[i][k] * fib.a[k][j];
	}
	cout << res[0][1] << nn;
	*/
}

int32_t main()
{
	int t;

	t = 1;
	while (t--) {
		solve();
	}
	return 0;
}
