/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_permutation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussaoui040@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 14:38:38 by os-moussao        #+#    #+#             */
/*   Updated: 2021/10/03 12:22:20 by os-moussao       ###   ########.fr       */
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

int	factorial(int n)
{
	int	res = 1;

	while (n > 1)
		res *= n--;
	return (res);
}

void	next_perm(int perm[], int n)
{
	int	j;

	for (int i = n - 2; i >= 0; i--)
	{
		j = i;
		while (perm[j] > perm[j + 1] && j < n - 1)
			ft_swap(&perm[j++], &perm[j + 1]);
		if (j != n - 1)
		{
			ft_swap(&perm[i], &perm[j + 1]);
			j++;
			while (perm[j] < perm[j - 1] && j > i + 1)
				ft_swap(&perm[j--], &perm[j - 1]);
			return ;
		}
	}
}

int	gen_perms(int n)
{
	int	p[n];
	int	count;
	int	total;

	// generate first permutation
	for (int i = 0; i < n; i++)
		p[i] = i + 1;

	total = factorial(n);
	count = 0;

	// print permutation by permutation untill hitting the last one
	while (count <= total)
	{
		put_perm(p, n);
		next_perm(p, n);
		count++;
	}
	return (total);
}

int	main(void)
{
	printf("\nTotal: %d", gen_perms(5));
}
