/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_permutations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussaoui040@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 16:11:13 by os-moussao        #+#    #+#             */
/*   Updated: 2021/09/30 16:17:17 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void	backtrack(char *stack, char *str, int index, int k, int *total)
{
	if (index == k)
	{
		printf("%s\n", stack);
		(*total)++;
		return ;
	}

	for ()
}

int	permutations(char *str, int k)
{
	int	total;
	int	stack[k + 1];

	stack[k] = 0;
	total = 0;

}

int	main(void)
{
	printf("\nTotal: %d\n", permutations("ABC", 3));
}
