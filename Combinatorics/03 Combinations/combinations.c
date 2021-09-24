/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combinations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussaoui040@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 15:35:58 by os-moussao        #+#    #+#             */
/*   Updated: 2021/09/24 15:56:25 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	put_comb(int stack[], int k)
{
	for (int i = 0; i < k; i++)
		printf("%d ", stack[i]);
	printf("\n");
}

void	backtrack(int stack[], int index, int start, int n, int k, int *total)
{
	if (index == k)
	{
		put_comb(stack, k);
		(*total)++;
		return ;
	}

	for (; start <= n; start++)
	{
		stack[index] = start;
		backtrack(stack, index + 1, start + 1, n, k, total);
	}
}

int	combinations(int n, int k)
{
	int	total;
	int	stack[k];

	total = 0;
	backtrack(stack, 0, 1, n, k, &total);
	return (total);
}

int	main(void)
{
	int	total;

	total = combinations(4, 2);
	printf("\nTotal combinations: %d\n", total);
}
