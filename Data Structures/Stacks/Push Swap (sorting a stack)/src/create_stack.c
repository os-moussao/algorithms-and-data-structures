/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 00:16:04 by omoussao          #+#    #+#             */
/*   Updated: 2021/12/14 01:54:22 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_atoi(const char *str)
{
	long long	res;
	int			sign;
	int			i;

	res = 0;
	sign = 1 - (str[0] == '-') * 2;
	i = (str[0] == '+' || str[0] == '-');
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		res = res * 10 + str[i++] - '0';
	res *= sign;
	if (str[i] || res > I_MAX || res < I_MIN)
		error();
	return ((int)res);
}

t_node	*create(char **av, int ac)
{
	t_node	*stack;

	stack = NULL;
	while (ac--)
		push(&stack, ft_atoi(av[ac]));
	return (stack);
}
