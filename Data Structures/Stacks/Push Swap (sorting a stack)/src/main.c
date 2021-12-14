/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 22:09:37 by omoussao          #+#    #+#             */
/*   Updated: 2021/12/14 01:50:52 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putnbr(int n)
{
	char	c;

	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}

void	disp(t_node *stack, char name)
{
	while (stack)
	{
		ft_putnbr(stack->data);
		write(1, "\n", 1);
		stack = stack->next;
	}
	write(1, "-\n", 2);
	write(1, &name, 1);
	write(1, "\n", 1);
}

int main(int ac, char **av)
{
	t_node	*a;

	a = create(av + 1, ac - 1);
	disp(a, 'a');
}
