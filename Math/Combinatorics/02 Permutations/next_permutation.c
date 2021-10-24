/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_permutation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussaoui040@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 14:38:38 by os-moussao        #+#    #+#             */
/*   Updated: 2021/10/03 14:24:19 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	put_perm(int perm[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", perm[i]);
	printf("\n");
}

void	swap(int *a, int *b)
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
	int i, j;

	i = n - 1;
	while (i > 0 && perm[i - 1] >= perm[i])
		i--;
	if (i)
	{
		j = n - 1;
		i--;
		while (perm[j] <= perm[i])
			j--;
		swap(&perm[i++], &perm[j]);
	}
	j = n - 1;
	for (; i < j; i++, j--)
		swap(&perm[i], &perm[j]);
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
	while (count < total)
	{
		put_perm(p, n);
		next_perm(p, n);
		count++;
	}
	return (total);
}

int	main(void)
{
	printf("\nTotal: %d", gen_perms(3));
}

/*
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
*/
