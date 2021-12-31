/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 19:17:45 by omoussao          #+#    #+#             */
/*   Updated: 2021/12/31 11:46:44 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	if (ac != 3)
		return (0);
	char	hash[256] = {0};

	char	*s1 = av[1], *s2 = av[2];
	while (*s1)
	{
		if (hash[(int)*s1] == 0)
		{
			putchar(*s1);
			hash[(int)*s1]++;
		}
		s1++;
	}
	while (*s2)
	{
		if (hash[(int)*s2] == 0)
		{
			putchar(*s2);
			hash[(int)*s2]++;
		}
		s2++;
	}
	putchar('\n');
}
