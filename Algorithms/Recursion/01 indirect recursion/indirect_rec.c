/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indirect_rec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussaoui040@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 20:34:39 by os-moussao        #+#    #+#             */
/*   Updated: 2021/09/08 20:40:22 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

// indirect recursion

void	fun_b(int n);

void	fun_a(int n)
{
	if (n <= 0)
		return ;
	printf("%d ", n);
	fun_b(n - 1);
}

void	fun_b(int n)
{
	if (n <= 1)
		return ;
	printf("%d ", n);
	fun_a(n / 2);
}

int	main(void)
{
	fun_a(20);
}
