/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussaoui040@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 21:54:03 by os-moussao        #+#    #+#             */
/*   Updated: 2021/09/21 22:05:32 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Merging 2 sorted arrays
**/

#include <stdio.h>
#include <stdlib.h>

int	*merge(int a1[], int a2[], int len1, int len2)
{
	int	i, j, k;
	int	*res;

	res = (int *)malloc((len1 + len2) * sizeof(int));
	i = j = k = 0;
	while (i < len1 && j < len2)
	{
		if (a1[i] < a2[j])
			res[k++] = a1[i++];
		else
			res[k++] = a2[j++];
	}
	while (i < len1)
		res[k++] = a1[i++];
	while (j < len2)
		res[k++] = a2[j++];
	return (res);
}

int	main(void)
{
	int	arr1[5] = {3, 8, 16, 20, 25};
	int	arr2[4] = {4, 7, 9, 22};
	int	*res;

	res = merge(arr1, arr2, 5, 4);
	for (int i = 0; i < 9; i++)
		printf("%d	", res[i]);
	free(res);
}
