/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magic_sums.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 13:00:03 by omoussao          #+#    #+#             */
/*   Updated: 2021/09/23 15:43:04 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool	is_magic_comb(int n, int *comb)
{
	int	sum, m_sum;

	m_sum = n * (n * n + 1) / 2;
	sum = 0;
	for (int i = 0; i < n; i++)
		sum += comb[i];
	return (sum == m_sum);
}

void	make_first_comb(int n, int *comb_buff)
{
	int	i;

	i = -1;
	while (++i < n)
		comb_buff[i] = i + 1;
}

int	is_max_elem(int n, int index, int *comb)
{
	return (comb[index] == index + n * n + 1 - n);
}

int	*next_comb(int n, int *comb)
{
	int	i;

	i = n - 1;
	while (i >= 0 && is_max_elem(n, i, comb))
		i--;
	comb[i++] += 1;
	while (i >= 0 && i < n)
	{
		comb[i] = comb[i - 1] + 1;
		i++;
	}
	return (comb);
}

void	put_comb(int n, int *comb)
{
	int	magic_sum;

	magic_sum = n * (n * n + 1) / 2;
	for (int i = 0; i < n; i++)
		printf("%d ", comb[i]);
	printf("	= %d\n", magic_sum);
}

void	print_magic_combs(int n, int *comb)
{
	if (is_magic_comb(n, comb))
		put_comb(n, comb);
	if (!is_max_elem(n, 0, comb))
		print_magic_combs(n, next_comb(n, comb));
}

void	magic_sums(int n)
{
	int	comb[n];

	if (n <= 2)
		return ;
	make_first_comb(n, comb);
	print_magic_combs(n, comb);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Usage: ./program [n]\n");
		return (1);
	}
	magic_sums(atoi(argv[1]));
}
