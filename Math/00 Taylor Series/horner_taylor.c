/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horner_taylor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussaoui040@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 22:38:22 by os-moussao        #+#    #+#             */
/*   Updated: 2021/09/09 23:30:32 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

double	taylor(double x, int n)
{
	double	res = 1;

	for (double i = n; i > 0; i--)
		res = res * x / i + 1;
}

int	main(void)
{
	printf("%lf", taylor(3, 15));
}
