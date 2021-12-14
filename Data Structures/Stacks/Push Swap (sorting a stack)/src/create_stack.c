/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 00:16:04 by omoussao          #+#    #+#             */
/*   Updated: 2021/12/15 00:28:24 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	arr_len(char **arr)
{
	int len;

	len = 0;
	while (*arr++)
		len++;
	return (len);
}

static int	_atoi(const char *str)
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
	char	**arr;
	int		len;

	stack = NULL;
	while (ac--)
	{
		arr = ft_split(av[ac], ' ');
		len = arr_len(arr);
		while (len--)
			push(&stack, _atoi(arr[len]));
	}
	return (stack);
}
