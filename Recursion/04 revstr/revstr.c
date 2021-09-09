/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussaoui040@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 21:25:18 by os-moussao        #+#    #+#             */
/*   Updated: 2021/09/08 21:29:45 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	revstr(char *str)
{
	if (!*str)
		return ;
	revstr(str + 1);
	printf("%c", *str);
}

int	main(void)
{
	revstr("1337");
}