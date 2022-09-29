/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cos.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussao@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 00:01:48 by os-moussao        #+#    #+#             */
/*   Updated: 2021/10/27 00:27:47 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>

double	modulo(double a, double b)
{
	while (a - b > 0)
		a -= b;
	return (a);
}

/*
 * Implementing cosine function using its taylor series expansion
 * cos(x) = sigma n: (-1)^n * x^(2n) / (2n)!
 * (for n ranging from 0 to the wanted precision (it could be +inf))
**/	
double	os_cos(double x)
{
	// cos(x) = cos(x mod 2pi)
	// solving for x modulo 2pi, to avoid overflows when entering a large number
	x = modulo(x, 2 * 3.14159265);
	double				cos = 1, p = 1;
	unsigned long long	fact = 1;

	for (int i = 1; i <= 9; i++)
	{
		p *= x*x;
		fact *= 2*i*(2*i-1);
		cos += ((1-2*(i%2)) * p) / fact;
	}
	return (cos);
}

int	main(void)
{
	printf("my cos: %lf\n", os_cos(3.14159265));
	printf("std cos: %lf\n\n", cos(3.14159265));

	printf("my cos: %lf\n", os_cos(10));
	printf("std cos: %lf\n\n", cos(10));

	printf("my cos: %lf\n", os_cos(2));
	printf("std cos: %lf\n\n", cos(2));

	printf("my cos: %lf\n", os_cos(1));
	printf("std cos: %lf\n", cos(1));
}
