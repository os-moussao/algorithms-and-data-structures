// https://codeforces.com/gym/102644/problem/A
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

#define int long long
#define double long double
#define REP(i, n) for(int i = 0; i < n; i++)
#define nn '\n'
#define ss ' '

struct Matrix
{
	double a[2][2] = {{0, 0}, {0, 0}};

	Matrix operator *(const Matrix &other)
	{
		Matrix prod;
		REP(i, 2)REP(j, 2)REP(k, 2)
			prod.a[i][j] += a[i][k] * other.a[k][j];
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

void solve(void)
{
	int n;
	double p;
	cin >> n >> p;

	Matrix prob;
	prob.a[0][0] = 1 - p;
	prob.a[0][1] = p;
	prob.a[1][0] = p;
	prob.a[1][1] = 1 - p;

	// REP(i, n) res = res * prob;
	Matrix res = pow(prob, n);

	cout << fixed  << setprecision(10) << res.a[0][0] << nn;
}

int32_t main()
{
	int	t;
	// cin >> t;
	t = 1;
	while (t--) {
		solve();
	}
	return 0;
}

/*
vector<double> dp;
dp.push_back(1.0);
dp.push_back(0.0);

for (int i = 0; i < n; i++)
{
	double new_happy = dp[0] * (1 - p) + dp[1] * p;
	double new_sad = dp[0] * p + dp[1] * (1 - p);
	dp[0] = new_happy;
	dp[1] = new_sad;
}
cout << fixed << setprecision(10) << dp[0] << nn;
*/
