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
			swap(a);
		}
	}
	else
	{
		if (a->data > a->next->data && a->next->data > bottom(a))
		{
			ft_putstr("sa\nrra\n");
			swap(a);
			rrotate(a);
		}
		else if (a->data > bottom(a))
		{
			ft_putstr("ra\n");
			rotate(a);
		}
		else
		{
			ft_putstr("sa\n");
			swap(a);
		}
	}
	return (a);
}

t_node	*insert_five_one(t_node *a, t_node *b)
{
	int		tmp;
	bool	rrb;

	if (b->data > bottom(a))
	{
		ft_putstr("pa\nra\n");
		push(&a, pop(&b));
		rotate(a);
	}
	else if (b->data > a->next->next->next->data)
	{
		ft_putstr("pa\nrra\nsa\nra\nra\n");
		push(&a, pop(&b));
		rrotate(a);
		swap(a);
		rotate(a);
		rotate(a);
	}
	else
	{
		tmp = b->data;
		rrb = tmp > a->data;
		while (a->data < tmp)
		{
			ft_putstr("pb\n");
			push(&b, pop(&a));
		}
		if (rrb)
		{
			ft_putstr("rrb\n");
			rrotate(b);
		}
		while (b)
		{
			ft_putstr("pa\n");
			push(&a, pop(&b));
		}
	}
	return (a);
}

t_node	*sort_five(t_node *a)
{
	t_node	*b;

	b = NULL;
	ft_putstr("pb\npb\n");
	push(&b, pop(&a));
	push(&b, pop(&a));
	if (!is_sorted(a))
		a = sort_three(a);
	ft_putstr("pa\n");
	push(&a, pop(&b));
	if (a->data > bottom(a))
	{
		ft_putstr("ra\n");
		rotate(a);
	}
	else if (a->data > a->next->next->data)
	{
		ft_putstr("rra\nsa\nra\nra\n");
		rrotate(a);
		swap(a);
		rotate(a);
		rotate(a);
	}
	else if (a->data > a->next->data)
	{
		ft_putstr("sa\n");
		swap(a);
	}
	return (insert_five_one(a, b));
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
	else if (len == 5)
		return (sort_five(a));

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
