// https://codeforces.com/gym/102644/problem/B
#include <iostream>
#include <iomanip>

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


	Matrix	a;
	a.a[0][0] = 19;
	a.a[0][1] = 7;
	a.a[1][0] = 6;
	a.a[1][1] = 20;

	cout << pow(a, n).a[0][0] << nn;
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

/**
 * if c[n][m] = a[n][p] * b[p][m]
 * then for each i in (0 --> n) and j in (0 --> m):
 * 	c[i][j] = sums of (a[i][k] + b[k][j]) for k in (0 --> p)
 **/
// psudocode for matrix multiplication:
//
// int [2][2]multiply(int a[2][2], int b[2][2])
// {
// 	int res[2][2] = {{0, 0}, {0, 0}};
// 	for (int i = 0; i < 2; i++)
// 		for (int j = 0; j < 2; j++)
// 			for (int k = 0; k < 2; k++)
// 				res[i][j] += (a[i][k] * b[k][j]) % MOD;
// 	return res;
//}
