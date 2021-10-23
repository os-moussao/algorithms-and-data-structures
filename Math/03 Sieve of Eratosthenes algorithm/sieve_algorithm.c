/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sieve_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussao@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 22:39:43 by os-moussao        #+#    #+#             */
/*   Updated: 2021/10/23 23:15:23 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/**
 * for more explanation:
 * https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
 * their animation is great and the first two paragraphs sum up everything
 *
 *
 * https://www.geeksforgeeks.org/sieve-of-eratosthenes/
 * read their explanation
 * try to code it yourself
 * then read their implementation. it's great
 *
 *
 * this algorithm is really fun to implement and easy
 *
 * to explore:
 *		segmented sieve (for a large n) https://www.geeksforgeeks.org/segmented-sieve/
 *		complexity analysis https://www.geeksforgeeks.org/how-is-the-time-complexity-of-sieve-of-eratosthenes-is-nloglogn/
**/

void	sieve_algorithm(int n)
{
	bool	prime[n + 1];
	memset(prime, 1, sizeof(prime));

	for (int i = 2; i * i <= n; i++)
	{
		if (prime[i])
		{
			for (int j = i * i; j <= n; j += i)
				prime[j] = false;
		}
	}

	for (int i = 2; i <= n; i++)
		if (prime[i])
			printf("%d  ", i);
	printf("\n");
}

int	main(void)
{
	int	n;

	scanf("%d", &n);
	printf("These are all the prime numbers less than or equal %d\n", n);
	sieve_algorithm(n);
}
