/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussaoui040@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 19:11:24 by os-moussao        #+#    #+#             */
/*   Updated: 2021/09/22 19:28:42 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	*arr_union(int arr1[], int arr2[], int len1, int len2)
{
	int	i, j, k, *res;

	res = malloc((len1 + len2) * sizeof(int));
	i = j = k = 0;
	while (i < len1 && j < len2)
	{
		if (arr1[i] < arr2[j])
			res[k++] = arr1[i++];
		else if (arr2[j] < arr1[i])
			res[k++] = arr2[j++];
		else
			res[k++] = arr1[i++], j++;
	}
	while (i < len1)
		res[k++] = arr1[i++];
	while (j < len2)
		res[k++] = arr2[j++];
	res = realloc(res, k * sizeof(int));
	return (res);
}

int	main(void)
{
	int	arr1[5] = {3, 8, 16, 25};
	int	arr2[4] = {4, 7, 8, 16};
	int	*res;

	res = arr_union(arr1, arr2, 4, 4);
	for (int i = 0; i < 6; i++)
		printf("%d	", res[i]);
	free(res);
}
