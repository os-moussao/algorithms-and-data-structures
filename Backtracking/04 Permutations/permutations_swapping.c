/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutations_swapping.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussaoui040@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 17:28:40 by os-moussao        #+#    #+#             */
/*   Updated: 2021/10/02 13:50:32 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * generating permutations by swapping elements
**/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void	ft_swap(char *c1, char *c2)
{
	char	tmp;

	tmp = *c1;
	*c1 = *c2;
	*c2 = tmp;
}

void	backtrack(char *str, int sw, int *total)
{
	if (!str[sw])
	{
		printf("%s\n", str);
		(*total)++;
		return ;
	}

	for (int i = sw; str[i]; i++)
	{
		ft_swap(&str[sw], &str[i]);
		backtrack(str, sw + 1, total);
		ft_swap(&str[sw], &str[i]);
	}
}

int	permutations(char *str)
{
	int	total = 0;

	backtrack(str, 0, &total);
	return (total);
}

int	main(void)
{
	char	str[5] = "ABCD";

	printf("\nTotal permutations: %d\n", permutations(str));
}
