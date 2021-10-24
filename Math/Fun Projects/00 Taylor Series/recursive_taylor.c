/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_taylor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussaoui040@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 21:12:39 by os-moussao        #+#    #+#             */
/*   Updated: 2021/09/09 22:27:53 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

double	taylor(double x, int n)
{
	static double	p = 1, f = 1;
	double			res;

	if (n == 0)
		return (1);
	res = taylor(x, n - 1);
	p *= x;
	f *= n;
	return (res + p / f);
}

int	main(void)
{
	printf("%lf", taylor(3, 50));
}
