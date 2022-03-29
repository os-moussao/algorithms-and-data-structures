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
	int a[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

	Matrix operator *(const Matrix &other)
	{
		Matrix prod;
		REP(i, 3)REP(j, 3)REP(k, 3) {
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
	Matrix res = get_id(3);
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

	int ans[1][3] = {{1, 2, 4}};

	if (n <= 3) {
		cout << ans[0][n - 1] << nn;
		return ;
	}

	Matrix tig;
	tig.a[0][0] = 0;
	tig.a[0][1] = 0;
	tig.a[0][2] = 1;
	tig.a[1][0] = 1;
	tig.a[1][1] = 0;
	tig.a[1][2] = 1;
	tig.a[2][0] = 0;
	tig.a[2][1] = 1;
	tig.a[2][2] = 1;
	
	tig = pow(tig, n - 3);
	int res[1][3] = {{0, 0, 0}};

	REP(i, 1)REP(j, 3)REP(k, 3) {
		res[i][j] += (ans[i][k] % MOD) * (tig.a[k][j] % MOD) % MOD;
		res[i][j] %= MOD;
	}

	cout << res[0][2] << nn;
}

int32_t main()
{
	int t;

	t = 1;
	while (t--) {
		solve();
	}
}
