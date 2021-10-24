/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_peak_2d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussaoui040@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 13:24:00 by os-moussao        #+#    #+#             */
/*   Updated: 2021/09/02 19:49:32 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * find peak in 2d array
*/

#include <stdio.h>

int	max_pos(int tab[], int len)
{
	int	max;

	max = 0;
	for (int i = 1; i < len; i++)
		if (tab[i] > tab[max])
			max = i;
	return (max);
}

int	find_peak(int mat[][4], int cols, int start, int end)
{
	int	mid, max;

	mid = (start + end) / 2;
	max = max_pos(mat[mid], cols);
	if (start == end)
		return (mat[mid][max]);
	if (mat[mid][max] < mat[mid - 1][max])
		return (find_peak(mat, cols, start, mid - 1));
	if (mat[mid][max] < mat[mid + 1][max])
		return (find_peak(mat, cols, mid + 1, end));
	return (mat[mid][max]);
}

int main()
{
    int arr[][4] = { { 1337, 100, 10, 10 },
                       { 14, 99, 12, 11 },
                       { 15, 9, 11, 19 },
                       { 16, 17, 19, 20 } };
 	printf("%d", find_peak(arr, 4, 0, 3));
}
