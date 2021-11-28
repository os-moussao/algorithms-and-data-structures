#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>
#include <limits.h>

using namespace std;

#define int long long
#define double long double

#define REP(i, n) for(int i = 0; i < n; i++)
#define nn '\n'
#define ss ' '

const int MOD = 1e9 + 7;

int minE(int *arr, int n)
{
	int min = LLONG_MAX, in = -1;

	for (int i = 0; i < n; i++)
	{
		if (!(arr[i]&1) && arr[i] <= min)
		{
			min = arr[i];
			in = i;
		}
	}
	return (in);
}

int maxE(int *arr, int n)
{
	int max = LLONG_MIN, in = -1;

	for (int i = 0; i < n; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
			in = i;
		}
	}
	return (in);
}

int maxO(int *arr, int n)
{
	int max = LLONG_MIN, in = -1;

	for (int i = 0; i < n; i++)
	{
		if (arr[i] > max && (arr[i]&1))
		{
			max = arr[i];
			in = i;
		}
	}
	return (in);
}


void solve()
{
	int n;
	cin >> n;

	int arr[n];
	REP(i, n) cin >> arr[i];

	int ma, mi;
	ma = maxE(arr, n);
	mi = minE(arr, n);
	while (1)
	{

		cout << nn;
		REP(i, n) cout << arr[i] << ss;
		cout << nn;

		if (mi == -1)
			break ;
		if (ma == mi)
		{
			ma = maxO(arr, n);
			if (arr[ma] == 1)
				break ;
		}
		arr[mi] >>= 1;
		arr[ma] <<= 1;
		ma = maxE(arr, n);
		mi = minE(arr, n);
	}

	int s = 0;
	REP(i, n) s += arr[i];
	cout << s << nn;
}

int32_t main()
{
	int t;

	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
