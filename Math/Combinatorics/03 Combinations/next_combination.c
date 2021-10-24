/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_combination.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussaoui040@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 15:58:00 by os-moussao        #+#    #+#             */
/*   Updated: 2021/10/03 15:59:43 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
