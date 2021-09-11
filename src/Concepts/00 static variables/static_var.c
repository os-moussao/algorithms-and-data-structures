/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussaoui040@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 12:48:56 by os-moussao        #+#    #+#             */
/*   Updated: 2021/09/08 19:31:00 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>


int	fun(int n)
{
	static int	x;	// this variable is created only once and it's given a value of 0 by default

	if (n == 0)
		return (0);
	x++;
	return (fun(n - 1) + x);
}

int	main(void)
{
	int	r;

	r = fun(5);
	printf("%d\n", r);;

	r = fun(5);
	printf("%d\n", r);;
}
