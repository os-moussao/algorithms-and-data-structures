/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parabolic_flight_mcpc_2018.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussao@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 21:21:35 by os-moussao        #+#    #+#             */
/*   Updated: 2021/10/12 23:40:12 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Problem from MCPC 2018
 * https://arena.moi/problem/mcpc2018parabolic
**/

#include <stdio.h>
#include <math.h>

int	main(void)
{
	int	T;

	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		int		N;
		double	x, y;

		scanf("%d%lf%lf", &N, &x, &y);
		x /= N * 2;
		printf("%d\n", (int)ceil(N * 2 * sqrt(x*x + y*y)));
	}
}
