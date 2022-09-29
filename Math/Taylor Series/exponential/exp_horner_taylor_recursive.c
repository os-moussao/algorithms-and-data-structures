/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_horner_taylor_recursive.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussaoui040@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 00:02:34 by os-moussao        #+#    #+#             */
/*   Updated: 2021/10/24 23:34:54 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

double	exp_recursive(double x, int n, double tmp)
{
	double	res;

	if (n == 0)
		return (tmp);
	res = tmp * x / n + 1;
	return (exp_recursive(x, n - 1, res));
}

double os_exp(double x, int n)
{
	return (exp_recursive(x, n, 1));
}

int	main(void)
{
	printf("%lf\n", os_exp(4, 50));
	printf("%lf\n", os_exp(4, 50));
}
