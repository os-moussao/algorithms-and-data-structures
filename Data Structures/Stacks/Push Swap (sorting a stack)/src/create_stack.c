/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 00:16:04 by omoussao          #+#    #+#             */
/*   Updated: 2021/12/17 17:16:46 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	arr_len(char **arr)
{
	int	len;

	len = 0;
	while (*arr++)
		len++;
	return (len);
}

static void	clear_arr(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
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

/*
 * need to clear the stack (or the array) when an error occures
 **/
t_node	*create(char **av, int ac)
{
	t_node	*stack;
	t_node	*tmp;
	char	**arr;
	int		len;

	stack = NULL;
	while (ac--)
	{
		arr = ft_split(av[ac], ' ');
		if (!*arr)
			error();
		len = arr_len(arr);
		while (len--)
			push(&stack, _atoi(arr[len]));
		clear_arr(arr);
		tmp = stack->next;
		while (tmp)
		{
			if (tmp->data == stack->data)
				error();
			tmp = tmp->next;
		}
	}
	return (stack);
}
