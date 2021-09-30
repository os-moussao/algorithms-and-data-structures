/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussaoui040@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 15:44:50 by os-moussao        #+#    #+#             */
/*   Updated: 2021/09/30 16:00:07 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>

void	put_perm(int stack[], int len)
{
	for (int i = 0; i < len; i++)
		printf("%d ", stack[i]);
	printf("\n");
}

bool	valid_choice(int stack[], int index, int choice)
{
	for (int i = 0; i < index; i++)
	{
		if (stack[i] == choice)
			return (false);
	}
	return (true);
}

void	backtrack(int stack[], int index, int n, int k, int *total)
{
	if (index == k)
	{
		put_perm(stack, k);
		(*total)++;
		return ;
	}

	for (int choice = 1; choice <= n; choice++)
	{
		if (valid_choice(stack, index, choice))
		{
			stack[index] = choice;
			backtrack(stack, index + 1, n, k, total);
		}
	}
}

int	permutations(int n, int k)
{
	int	total;
	int	stack[k];

	total = 0;
	backtrack(stack, 0, n, k, &total);
	return (total);
}

int	main(void)
{
	printf("\nTotal: %d\n", permutations(4, 4));
}
