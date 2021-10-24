/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussaoui040@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 23:10:55 by os-moussao        #+#    #+#             */
/*   Updated: 2021/09/09 17:54:33 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

// Time: m*n
// Space: m*n
int	grid_paths(int n, int m)
{
	int	arr[n][m];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (i == 0 || j == 0)
				arr[i][j] = 1;
			else
				arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
		}
	}
	return (arr[n - 1][m - 1]);
}


// Another dynamic programming solution: using only one dimensional array of size max(m, n)
// Space Complexity of max(n, m) rather than m*n (grid_paths)
// Time complexity: m*n
int uniquePaths(int n, int m)
{
	int	max = (n >= m)? n: m;
	int	min = (max == n)? m: n;
	int	arr[max];
    
	for (int i = 0; i < max; i++)
		arr[i] = 1;
	for (int i = 1; i < min; i++)
	{
		for (int j = i; j < max; j++)
		{
			if (j == i)
				arr[j] *= 2;
			else
				arr[j] += arr[j - 1];
		}
	}
	return (arr[max - 1]);
}

int	main(void)
{
	int	a, b;

	a = 4;
	b = 4;
	printf("paths available: %d", grid_paths(a, b));
}
