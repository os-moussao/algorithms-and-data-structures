/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   power_O_logN.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussaoui040@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 21:49:16 by os-moussao        #+#    #+#             */
/*   Updated: 2021/09/08 22:28:09 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

// O(n) = log(n)
int	power(int base, int exp)
{
	if (exp <= 0)
		return (exp == 0);
	if (exp % 2 == 0)
		return (power(base * base, exp / 2));
	return (base * power(base * base, (exp - 1) / 2));
}

// my leet code solution
double myPow(double x, long long n){
    if (n == 0)
        return (1);
    if (n < 0)
        return (1 / myPow(x, -n));
    if (n % 2 == 0)
        return (myPow(x * x, n / 2));
    else
        return (x * myPow(x * x, (n - 1) / 2));
}

int	main(void)
{
	printf("%d", power(2, 3));
}
