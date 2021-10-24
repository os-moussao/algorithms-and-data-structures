/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_iterative_taylor.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussaoui040@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 20:46:48 by os-moussao        #+#    #+#             */
/*   Updated: 2021/10/24 23:35:12 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>

double	os_exp(double x, int n)
{
	double	res = 1;
	double	pow = 1;
	double	fac = 1;

	for (int i = 1; i <= n; i++)
	{
		pow *= x;
		fac *= i;
		res += pow / fac;
	}
	return (res);
}

int	main(void)
{
	printf("%lf", os_exp(3, 50));
}
