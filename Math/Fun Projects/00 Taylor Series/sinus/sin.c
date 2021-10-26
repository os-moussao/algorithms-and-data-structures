/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sin.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussao@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 22:37:31 by os-moussao        #+#    #+#             */
/*   Updated: 2021/10/26 23:49:24 by os-moussao       ###   ########.fr       */
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
 * Implementing sine function 
 * using its taylor series expantion
 * sin(x) = sigma n: (-1)^n * x^(2*n+1) / (2*n+1)!
 * (n ranging from 0 to the wanted precision (it could be +inf))
 *
 * I could not exceed a precision of 9
 * because of the overflow in the factorial value
 * which overflows when exceeding 19!
**/
double	os_sin(double x)
{
	// sin(x) = sin(x mod 2pi)
	// solving for x modulo 2pi, to avoid overflows when entering a large number
	x = modulo(x, 2 * 3.14159265);
	double				sin = x, p = x;
	unsigned long long	fact = 1;

	for (int i = 1; i <= 9; i++)
	{
		p *= x*x;
		fact *= 2*i*(2*i+1);
		sin += ((1-2*(i%2)) * p) / fact;
	}
	return (sin);
}

int	main(void)
{
	printf("my sin: %lf\n", os_sin(3.14159265));
	printf("std sin: %lf\n\n", sin(3.14159265));

	printf("my sin: %lf\n", os_sin(3));
	printf("std sin: %lf\n\n", sin(3));

	printf("my sin: %lf\n", os_sin(2));
	printf("std sin: %lf\n\n", sin(2));

	printf("my sin: %lf\n", os_sin(1));
	printf("std sin: %lf\n\n", sin(1));

	printf("my sin: %lf\n", os_sin(10));
	printf("std sin: %lf\n", sin(10));


	/*
	 *
	 * lol it worked!
	 * */
}
