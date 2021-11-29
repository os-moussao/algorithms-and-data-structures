/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 19:26:39 by omoussao          #+#    #+#             */
/*   Updated: 2021/11/25 19:37:42 by omoussao         ###   ########.fr       */
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
	while (*s2)
	{
		hash[*s2] = 1;
		s2++;
	}
	while (*s1)
	{
		if (hash[*s1] == 1)
		{
			putchar(*s1);
			hash[*s1] = 0;
		}
		s1++;
	}
	putchar('\n');
}