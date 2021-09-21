/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussaoui040@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 12:58:03 by os-moussao        #+#    #+#             */
/*   Updated: 2021/09/21 13:19:18 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>

bool	in_order(int comp, int order)
{
	if (order > 0)
		return (comp >= 0);
	if (order < 0)
		return (comp <= 0);
	return (comp == 0);
}

bool	is_sorted(int arr[], int len)
{
	int	order;

	if (len <= 2)
		return (true);
	order = arr[len - 1] - arr[0];
	for (int i = 0; i < len - 1; i++)
	{
		if (!in_order(arr[i + 1] - arr[i], order))
			return (false);
	}
	return (true);
}

int	main(void)
{
	int	arr1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int	arr2[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	int	arr3[4] = {1929, 1929, 1929, 1929};
	int	arr4[10] = {10, 9, 8, 7, 18, 19, 4, 3, 2, 1};

	printf("Array1: %s\n", is_sorted(arr1, 10)? "sorted": "not sorted");
	printf("Array2: %s\n", is_sorted(arr2, 10)? "sorted": "not sorted");
	printf("Array3: %s\n", is_sorted(arr3, 4)? "sorted": "not sorted");
	printf("Array4: %s\n", is_sorted(arr4, 10)? "sorted": "not sorted");
}
