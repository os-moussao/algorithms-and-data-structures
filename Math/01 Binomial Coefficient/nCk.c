/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nCk.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussaoui040@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 21:40:48 by os-moussao        #+#    #+#             */
/*   Updated: 2021/09/11 22:14:14 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

// Binomial Coefficient function
// Or Choose(n, k): number of (unordered) ways we can choose k elements from n elements
// Or nCk
//
//
// nCk	= n! / k! * (n - k)!
// 		= (n * n-1 * ... * n-k+1) / k!			this method has k iterations
// 		= (n * n-1 * ... * k+1) / (n - k)!		this method has n-k iterations
//
//
// we can choose the minimum of k and n-k,
// then decide which method to use,
// to have the least number of iterations
//
//
// but I'll just go on with the second methos
// as both of them have a time complexity of O(n)
long long	choose(int n, int k)
{
	long long	res = 1;

	for (int i = k + 1; i <= n; i++)
		res *= i,
		res /= i - k;
	return (res);
}

int	main(void)
{
	printf("%ld\n", choose(10, 4));
}
