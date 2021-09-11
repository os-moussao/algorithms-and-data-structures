/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horner_taylor_recursive.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussaoui040@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 00:02:34 by os-moussao        #+#    #+#             */
/*   Updated: 2021/09/11 10:29:33 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

double	taylor_recursive(double x, int n, double tmp)
{
	double	res;

	if (n == 0)
		return (tmp);
	res = tmp * x / n + 1;
	return (taylor_recursive(x, n - 1, res));
}

double taylor(double x, int n)
{
	return (taylor_recursive(x, n, 1));
}

int	main(void)
{
	printf("%lf\n", taylor(4, 50));
	printf("%lf\n", taylor(4, 50));
}
