// https://codeforces.com/gym/102644/problem/B
#include <iostream>
#include <iomanip>

using namespace std;

#define int long long
#define double long double
#define nn '\n'
#define ss ' '

const int MOD =  1e9 + 7;

int	[2][2]matrix_power(int a[2][2], int n);

int32_t main()
{
	int n;
	cin >> n;

	int	a[2][2] = {
		{19, 7},
		{6, 20}
	};

	cout << matrix_power(a, n)[0][0] << nn;

	return 0;
}

/**
 * if c[n][m] = a[n][p] * b[p][m]
 * then for each i in (0 --> n) and j in (0 --> m):
 * 	c[i][j] = sums of (a[i][k] + b[k][j]) for k in (0 --> p)
 **/
int [2][2]multiply(int a[2][2], int b[2][2])
{
	int res[2][2] = {{0, 0}, {0, 0}};
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			for (int k = 0; k < 2; k++)
				res[i][j] += (a[i][k] * b[k][j]) % MOD;
	return res;
}

int [2][2]matrix_power(int a[2][2], int n)
{
	int res[2][2] = {
		{1, 1},
		{1, 1}
	};
	if (n == 0)
		return res;
	while (n > 0)
	{
		if (n % 2 == 1)
		{
			res = multiply(res, a);
			n--;
		}
		else
		{
			a = multiply(a, a);
			n /= 2;
		}
	}
	return res;
}
