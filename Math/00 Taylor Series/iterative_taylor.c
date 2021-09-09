/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterative_taylor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussaoui040@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 20:46:48 by os-moussao        #+#    #+#             */
/*   Updated: 2021/09/09 21:03:07 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>

double	taylor(double x, int n)
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
	printf("%lf", taylor(3, 50));
}
