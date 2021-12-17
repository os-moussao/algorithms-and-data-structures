/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 21:53:20 by omoussao          #+#    #+#             */
/*   Updated: 2021/12/16 19:09:56 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	is_sorted(t_node *stack)
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

t_node	*sort_stack(t_node *a)
{
	t_node	*b;

	if (is_sorted(a))
		return (a);
	if (!(a->next->next))
	{
		if (a->data > a->next->data)
		{
			ft_putstr("sa\n");
			swap(a);
		}
		return (a);
	}
	b = NULL;
	ft_putstr("pb\n");
	push(&b, pop(&a));
	while (a)
	{
		ft_putstr("pb\n");
		push(&b, pop(&a));
		while (b->next && b->data < b->next->data)
		{
			ft_putstr("sb\n");
			swap(b);
			ft_putstr("pa\n");
			push(&a, pop(&b));
		}
	}
	while (b)
	{
		ft_putstr("pa\n");
		push(&a, pop(&b));
	}
	return (a);
}
