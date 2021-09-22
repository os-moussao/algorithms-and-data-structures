/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussaoui040@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 19:38:58 by os-moussao        #+#    #+#             */
/*   Updated: 2021/09/22 20:04:30 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	*inter(int arr1[], int arr2[], int len1, int len2)
{
	int	i, j, k, *res;

	res = malloc(len1 * sizeof(int));
	i = j = k = 0;
	while (i < len1 && j < len2)
	{
		if (arr1[i] < arr2[j])
			i++;
		else if (arr2[j] < arr1[i])
			j++;
		else
			res[k++] = arr1[i++], j++;
	}
	res = realloc(res, k * sizeof(int));
	return (res);
}

int	main(void)
{
	int	arr1[5] = {3, 8, 16, 25};
	int	arr2[4] = {4, 7, 8, 16};
	int	*res;

	res = inter(arr1, arr2, 4, 4);
	for (int i = 0; i < 2; i++)
		printf("%d	", res[i]);
	free(res);
}
