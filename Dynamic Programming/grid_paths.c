/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussaoui040@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 23:10:55 by os-moussao        #+#    #+#             */
/*   Updated: 2021/09/09 11:01:38 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

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

int	main(void)
{
	int	a, b;

	a = 51;
	b = 9;
	printf("paths available: %d", grid_paths(a, b));
}
