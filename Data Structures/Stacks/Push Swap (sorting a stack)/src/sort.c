/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 21:53:20 by omoussao          #+#    #+#             */
/*   Updated: 2021/12/20 21:04:56 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	sorted(t_node *stack)
{
	int	x;

	if (!stack || !stack->next)
		return (true);
	x = stack->data;
	stack = stack->next;
	while (stack)
	{
		if (stack->data < x)
			return (false);
		x = stack->data;
		stack = stack->next;
	}
	return (true);
}

static int find_min(t_node *a)
{
	int	min;
	int	min_i;
	int	i;

	i = 0;
	min = I_MAX;
	while (a)
	{
		if (a->data <= min)
		{
			min = a->data;
			min_i = i;
		}
		i++;
		a = a->next;
	}
	return (min_i);
}

static int find_max(t_node *a)
{
	int	max;
	int	max_i;
	int	i;

	i = 0;
	max = I_MIN;
	while (a)
	{
		if (a->data >= max)
		{
			max = a->data;
			max_i = i;
		}
		i++;
		a = a->next;
	}
	return (max_i);
}

t_node	*min_up(t_node *a, int len)
{
	int	min;

	min = find_min(a);
	if (min < len / 2 + (len & 1))
	{
		while (min--)
		{
			ft_putstr("ra\n");
			rotate(a);
		}
	}
	else
	{
		min = len - min;
		while (min--)
		{
			ft_putstr("rra\n");
			rrotate(a);
		}
	}
	return (a);
}

t_node	*sort_three(t_node *a)
{
	int	max;

	max = find_max(a);
	if (max == 0)
	{
		ft_putstr("ra\n");
		rotate(a);
	}
	else if (max == 1)
	{
		ft_putstr("rra\n");
		rrotate(a);
	}
	if (a->data > a->next->data)
	{
		ft_putstr("sa\n");
		swap(a);
	}
	return (a);
}

t_node	*selection_sort(t_node *a, int len)
{
	t_node	*b;

	b = NULL;
	while (len > 3)
	{
		a = min_up(a, len--);
		ft_putstr("pb\n");
		push(&b, pop(&a));
	}
	a = sort_three(a);
	while (b)
	{
		ft_putstr("pa\n");
		push(&a, pop(&b));
	}
	return (a);
}

t_node	*sort_stack(t_node *a)
{
	int		len;

	// if sorted quit
	if (sorted(a))
		return (a);

	// calc stack len
	len = stack_len(a);

	// in case if two or three
	if (len == 2)
	{
		if (a->data > a->next->data)
			ft_putstr("sa\n");
		return (a);
	}
	return (selection_sort(a, len));
}