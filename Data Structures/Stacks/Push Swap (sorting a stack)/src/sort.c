/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 21:53:20 by omoussao          #+#    #+#             */
/*   Updated: 2021/12/18 01:54:39 by omoussao         ###   ########.fr       */
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

// you may not apply the instructions if you want
t_node	*sort_three(t_node *a)
{
	if (a->data < a->next->data)
	{
		ft_putstr("rra\n");
		rrotate(a);
		if (a->data > a->next->data)
		{
			ft_putstr("sa\n");
			//swap(a);
		}
	}
	else
	{
		if (a->data > a->next->data && a->next->data > bottom(a))
		{
			ft_putstr("sa\n");
			//swap(a);
			ft_putstr("rra\n");
			//rrotate(a);
		}
		else if (a->data > bottom(a))
		{
			ft_putstr("ra\n");
			//rotate(a);
		}
		else
		{
			ft_putstr("sa\n");
			//swap(a);
		}
	}
	return (a);
}

t_node	*sort_stack(t_node *a)
{
	t_node	*b;
	int		len;

	// if sorted quit
	if (is_sorted(a))
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
	else if (len == 3)
		return (sort_three(a));

	// dumb algorithm for the remaining lengths
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
