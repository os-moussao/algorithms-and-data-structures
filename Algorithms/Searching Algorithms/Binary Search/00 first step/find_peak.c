/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_peak.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussaoui040@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 23:01:17 by os-moussao        #+#    #+#             */
/*   Updated: 2021/09/02 13:38:18 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * find peak in 1d array
*/

#include <stdio.h>

int	find_peak(int *tab, int start, int end)
{
	int	mid;

	mid = (end + start) / 2;
	if (start == end)
		return (start);
	if (tab[mid] < tab[mid + 1])
		return (find_peak(tab, mid + 1, end));
	if (tab[mid] < tab[mid - 1])
		return (find_peak(tab, start, mid - 1));
	return (mid);
}

int	main(void)
{
	int	tab[] = {11, 10, 9, 8, 9, 6, 5};
	printf("%d", tab[find_peak(tab, 0, 6)]);
}
