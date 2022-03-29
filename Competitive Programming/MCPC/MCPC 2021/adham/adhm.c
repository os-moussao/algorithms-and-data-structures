#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <math.h>
#include <limits.h>

bool	solve2(int *stack, int n, int x)
{
	for (int i = 0; i < n; i++)
	{
		int	sum = 0;
		for (int j = i; j < n; j++)
		{
			if (i == 0 && j == n - 1)
				break ;
			sum += stack[j];
			if (sum % x == 0)
				return (false);
		}
	}
	return (true);
}

bool	backtrack(int *stack, int *valid, int index, int sum, int n, int s, int x)
{
	if (index == n && s == sum)
	{
		if (solve2(stack, n, x))
		{
			/*
			printf("Solution:\n", sum, s);
			for (int i = 0; i < n; i++)
				printf("%d ", stack[i]);
			printf("\n");
			*/
			return (true);
		}
		return (false);
	}

	if (sum > s)
		return (false);

	for (int i = 1; i <= s; i++)
	{
		if (valid[i])
		{
			stack[index] = i;
			valid[i] = 0;
			if (backtrack(stack, valid, index + 1, sum + i, n, s, x))
				return (true);
			valid[i] = 1;
		}
	}
	return (false);
}

bool	permutations(int n, int s, int x)
{
	int	valid[s + 1];
	int	stack[n];

	for (int i = 0; i < s + 1; i++)
		valid[i] = 1;
	return (backtrack(stack, valid, 0, 0, n, s, x));
}

bool	solve(int n, int s, int x)
{
	if (n > s)
		return (false);
	else if (n == s)
		return (x <= n - 1);
	else
	{
		if (x >= s)
			return (true);
		else
		{
			// process
			// solve2():
			// generate all possible permutation with sum s [of numbers from 1 to (s - n + 1)]
			// for each permutation:
			// 		all possible subarrays with sum divisile by x
			// 		if no possible subarray ==> true
			// 		else ==> false
			return (permutations(n, s, x));
		}
	}
}

int	main(void)
{
	FILE	*in = freopen("adhm.in", "r", stdin);
	int	T;

	scanf("%d", &T);
	while (T-- > 0)
	{
		int	n, s, x;

		scanf("%d%d%d", &n, &s, &x);
		printf("%s\n", solve(n, s, x)? "Adhm": "Methat");
	}
	fclose(in);
}
