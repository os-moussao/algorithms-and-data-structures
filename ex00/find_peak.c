/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_peak.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussaoui040@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 23:01:17 by os-moussao        #+#    #+#             */
/*   Updated: 2021/09/01 23:09:55 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	find_peak(int *tab, int start, int end, int len)
{
	if (tab[start + len/2] < tab[start + len/2 + 1])
		return (find_peak(tab, start + len/2 + 1, end, len / 2));
	else if ((tab[start + len/2] < tab[start + len/2 - 1]))
		return (find_peak(tab, start, start + len/2 - 1, len / 2));
	else
		return (len/2);
}

int	main(void)
{
	int	tab[10] = {0,1,2,3,4,5,6,7,8,9};
	printf("%d", tab[find_peak(tab, 0, 9, 10)]);
}
