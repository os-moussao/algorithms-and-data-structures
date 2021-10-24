/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nested_rec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussaoui040@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 21:05:41 by os-moussao        #+#    #+#             */
/*   Updated: 2021/09/08 21:19:27 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	fun(int n)
{
	if (n > 100)
		return (n - 10);
	return fun(fun(n + 11));
}

int	main(void)
{
	int	res;

	res = fun(99);
	printf("%d", res);
}
