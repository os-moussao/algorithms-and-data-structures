/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_permutations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussaoui040@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 16:11:13 by os-moussao        #+#    #+#             */
/*   Updated: 2021/09/30 16:45:19 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void	backtrack(char *stack, char *str, int valid[], int index, int len, int k, int *total)
{
	if (index == k)
	{
		printf("%s\n", stack);
		(*total)++;
		return ;
	}

	for (int choice = 0; choice < len; choice++)
	{
		if (valid[choice])
		{
			stack[index] = str[choice];
			valid[choice] = 0;
			backtrack(stack, str, valid, index + 1, len, k, total);
			valid[choice] = 1;
		}
	}
}

int	permutations(char *str, int k)
{
	int		total = 0, len = strlen(str);
	int		valid[len];
	char	stack[k + 1];

	stack[k] = 0;
	if (k <= 0 || k > len)
		return (0);
	for (int i = 0; i < len; i++)
		valid[i] = 1;
	backtrack(stack, str, valid, 0, len, k, &total);
	return (total);
}

int	main(void)
{
	printf("\nTotal: %d\n", permutations("ABCD", 4));
}
