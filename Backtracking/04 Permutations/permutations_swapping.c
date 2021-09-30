/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutations_swapping.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussaoui040@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 17:28:40 by os-moussao        #+#    #+#             */
/*   Updated: 2021/09/30 17:56:14 by os-moussao       ###   ########.fr       */
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

void	backtrack(char *str, int index, char *origin)
{
	if (!str[index])
		return ;

	for (int i = 0; str[i]; i++)
	{
		printf("%s\n", str);
		ft_swap(&str[index], &str[i]);
	}
	strcpy(str, origin);
	backtrack(str, index + 1, origin);
}

int	permutations(char *str)
{
	char	*copy;

	copy = strdup(str);
	backtrack(str, 0, copy);
	free(copy);
	return (0);
}

int	main(void)
{
	char	str[4] = "ABC";

	permutations(str);
}
