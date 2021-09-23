/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_duplicates.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussaoui040@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 18:59:38 by os-moussao        #+#    #+#             */
/*   Updated: 2021/09/23 19:09:51 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Finding duplicates in a sorted array
*/

#include <stdio.h>

void	find_dup(int arr[], int len)
{
	int	i, j;

	if (len < 2)
		return ;
	i = 0;
	while (i < len - 1)
	{
		j = 0;
		while (arr[i + 1] == arr[i] && i < len - 1)
			i++, j++;
		if (j)
			printf("%d	", arr[i]);
		i++;
	}
	printf("\n");
}

int	main(void)
{
	int	arr[10] = {1, 2, 3, 3, 4, 5, 6, 6, 6, 7};
	find_dup(arr, 10);
}
