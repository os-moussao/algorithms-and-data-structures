#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <math.h>
#include <limits.h>

void	swap(int *a, int *b)
{
	int	tmp = *a;

	*a = *b;
	*b = tmp;
}

int	calc_minmin(int *arr, int N)
{
	int	min1 = 0;
	int	min2 = 0;

	for (int i = 0; i < N - 2; i++)
	{
		if (i % 2 == 0)
			min1 += abs(arr[i] - arr[i + 2]);
		else
			min2 += abs(arr[i] - arr[i + 2]);
	}
	return (min1 < min2? min1: min2);
}

void	perm(int *arr, int N, int sw, int *min)
{
	if (sw == N)
	{
		int	m = calc_minmin(arr, N);
		if (m < *min)
			*min = m;
		return ;
	}

	for (int i = sw; i < N; i++)
	{
		swap(&arr[sw], &arr[i]);
		perm(arr, N, sw + 1, min);
		swap(&arr[sw], &arr[i]);
	}
}

int	minmin(int *arr, int N)
{
	int	min = INT_MAX;

	perm(arr, N, 0, &min);
	return (min);
}

int	main(void)
{
	FILE	*in = freopen("min.in", "r", stdin);
	int	N;

	scanf("%d", &N);
	int	arr[N];
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	printf("%d\n", minmin(arr, N));
	fclose(in);
}
