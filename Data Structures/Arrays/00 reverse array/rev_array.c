/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_array.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussaoui040@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 10:02:01 by os-moussao        #+#    #+#             */
/*   Updated: 2021/09/21 10:09:47 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	rev_array(int *arr, int len)
{
	int	i, j;

	for (i = 0, j = len - 1; i < j; i++, j--)
		ft_swap(&arr[i], &arr[j]);
}

int	main(void)
{
	int	arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	rev_array(arr, 10);
	for (int i = 0; i < 10; i++)
		printf("%d	", arr[i]);
}
