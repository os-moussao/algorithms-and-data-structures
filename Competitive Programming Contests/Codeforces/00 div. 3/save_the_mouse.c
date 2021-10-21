#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>

int solve(char *arr, long long n)
{
	int ans = 0;
	long long i = 0;

	while (i < n)
	{
		long long j = n - 1;
		while (arr[j] == 0 && j >= 0)
			j--, i++;
		if (j >= 0 && arr[j] && i < n)
		{
			arr[j]--;
			ans++;
		}
	}
	return ans;
}

int	main(void)
{
	int	T;

	scanf("%d", &T);
	while (T-- > 0)
	{
		long long	n, k, i, j;

		scanf("%lld%lld", &n, &k);
		char arr[n];
		for (i = 0; i < n; i++)
			arr[i] = 0;
		for (j = 0; j < k; j++)
		{
			long long m;
			scanf("%lld", &m);
			arr[m - 1]++;
		}
		printf("%d\n", solve(arr, n));
	}
}
