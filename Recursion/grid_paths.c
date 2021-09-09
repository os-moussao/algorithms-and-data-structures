/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussaoui040@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 23:10:55 by os-moussao        #+#    #+#             */
/*   Updated: 2021/09/09 10:29:37 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	grid_paths_me(int n, int m)
{
	int	sum = 0;

	if (n == 1 || m == 1)
		return (1);
	for (int i = 1; i <= n; i++)
		sum += grid_paths_me(i, m - 1);
	return (sum);
}


int	grid_paths(int n, int m)
{
	if (n == 1 || m == 1)
		return (1);
	return (grid_paths(n - 1, m) + grid_paths(n, m - 1));
}

int	main(void)
{
	int	a, b;

	a = 51;
	b = 9;
	printf("paths available: %d", grid_paths(a, b));
}
