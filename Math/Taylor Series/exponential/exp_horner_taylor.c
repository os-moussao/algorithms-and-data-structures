/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_horner_taylor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussaoui040@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 22:38:22 by os-moussao        #+#    #+#             */
/*   Updated: 2021/10/24 23:34:27 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

double	os_exp(double x, int n)
{
	double	res = 1;

	for (double i = n; i > 0; i--)
		res = res * x / i + 1;
	return (res);
}

int	main(void)
{
	printf("%lf", os_exp(3, 50));
}
