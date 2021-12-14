/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 21:53:20 by omoussao          #+#    #+#             */
/*   Updated: 2021/12/14 22:36:15 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_node **a)
{
	t_node	*b;

	if (!((*a)->next->next))
	{
		if ((*a)->data > (*a)->next->data)
		{
			ft_putstr("sa\n");
			swap(*a);
		}
		return ;
	}
	b = NULL;
	ft_putstr("pb\n");
	push(&b, pop(a));
	while (*a)
	{
		//if ((*a)->data > b->data)
		//{
			ft_putstr("pb\n");
			push(&b, pop(a));
		//}
		//else
		//{
		if (b->data < b->next->data)
		{
			ft_putstr("sb\n");
			swap(b);
			ft_putstr("pa\n");
			push(a, pop(&b));
		}
		//}
	}
	disp(*a, 'a');
	disp(b, 'b');
}
