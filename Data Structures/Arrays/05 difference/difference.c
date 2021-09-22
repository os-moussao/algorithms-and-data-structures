/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   difference.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussaoui040@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 20:11:31 by os-moussao        #+#    #+#             */
/*   Updated: 2021/09/22 20:18:20 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

/**
 * A - B: elements that are in A and doesn't exist in B
*/
int	*difference(int A[], int B[], int len1, int len2)
{
	int	i, j, k, *res;
	
	res = malloc(len1 * sizeof(int));
	i = j = k = 0;
	while (i < len1 && j < len2)
	{
		if (A[i] < B[j])
			res[k++] = A[i++];
		else if (B[j] < A[i])
			j++;
		else
			i++, j++;
	}
	while (i < len1)
		res[k++] = A[i++];
	res = realloc(res, k * sizeof(int));
	return (res);
}

int	main(void)
{
	int	arr1[5] = {3, 8, 16, 25};
	int	arr2[4] = {4, 7, 8, 16};
	int	*res;

	res = difference(arr1, arr2, 4, 4);
	for (int i = 0; i < 2; i++)
		printf("%d	", res[i]);
	free(res);
}
