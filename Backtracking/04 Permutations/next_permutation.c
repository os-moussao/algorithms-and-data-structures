/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_permutation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussaoui040@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 14:38:38 by os-moussao        #+#    #+#             */
/*   Updated: 2021/10/02 17:07:31 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	put_perm(int perm[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", perm[i]);
	printf("\n");
}

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	next_perm(int perm[], int n)
{
	int	j, last;

	last = n - 1;
	for (int i = n - 2; i >= 0; i--)
	{
		if (perm[i] < perm[last])
		{
			ft_swap(&perm[i], &perm[i + 1]);
			j = last;
			while (j > i + 1 && perm[j] < perm[j - 1])
				ft_swap(&perm[j], &perm[j - 1]);
			return ;
		}
		else
		{
			j = i;
			while (perm[j + 1] < perm[j] && j < n - 1)
			{
				ft_swap(&perm[j], &perm[j + 1]);
				last++;
				j++;
			}
		}
	}
}

int	main(void)
{
	int	perm[4] = {2, 3, 4, 1};

	next_perm(perm, 4);
	put_perm(perm, 4);
	printf("\nExp: 2 4 1 3");
}

/*
1 2 3 4
1 2 4 3
1 3 2 4
1 3 4 2
1 4 2 3
1 4 3 2
2 1 3 4
2 1 4 3
2 3 1 4
2 3 4 1
2 4 1 3
2 4 3 1
3 1 2 4
3 1 4 2
3 2 1 4
3 2 4 1
3 4 1 2
3 4 2 1
4 1 2 3
4 1 3 2
4 2 1 3
4 2 3 1
4 3 1 2
4 3 2 1
*/
