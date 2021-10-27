#include <stdio.h>

long long unsigned int	memo[21][21] = {{0}};

long long unsigned int	paths(int n, int m)
{
	if (n == 1)
		return (m + 1);
	if (m == 1)
		return (n + 1);
	if (!memo[n][m] && !memo[m][n])
		memo[n][m] = memo[m][n] = paths(n - 1, m) + paths(n, m - 1);
	return memo[n][m];
}

int	main(void)
{
	printf("%llu\n", paths(20, 20));
}
