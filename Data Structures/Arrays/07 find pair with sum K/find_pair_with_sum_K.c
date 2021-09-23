/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pair_with_sum_K.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussaoui040@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 21:10:59 by os-moussao        #+#    #+#             */
/*   Updated: 2021/09/23 21:17:42 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Find pair of elements with sum K in a sorted array (without duplicates)
*/

#include <stdio.h>

void	find_pair(int arr[], int len, int K)
{
	int	i, j;

	i = 0;
	j = len - 1;
	while (i < j)
	{
		if (arr[i] + arr[j] > K)
			j--;
		else if (arr[i] + arr[j] < K)
			i++;
		else // if arr[i] + arr[j] == K
			printf("%d + %d = %d\n", arr[i++], arr[j--], K);
	}
}

int	main(void)
{
	int	arr[10] = {1, 3, 4, 5, 6, 8, 9, 10, 12, 14};
	find_pair(arr, 10, 11);
}
