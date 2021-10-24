/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_rev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussaoui040@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 21:25:18 by os-moussao        #+#    #+#             */
/*   Updated: 2021/10/10 16:26:24 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	print_rev(char *str)
{
	if (!*str)
		return ;
	print_rev(str + 1);
	printf("%c", *str);
}

int	main(void)
{
	print_rev("1337");
}
