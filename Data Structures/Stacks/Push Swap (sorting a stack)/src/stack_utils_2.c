/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 23:18:47 by omoussao          #+#    #+#             */
/*   Updated: 2021/12/18 01:45:18 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_node *stack)
{
	while (stack->next)
	{
		ft_swap(&(stack->data), &(stack->next->data));
		stack = stack->next;
	}
}

void	rrotate(t_node *stack)
{
	if (!(stack->next))
		return ;
	rrotate(stack->next);
	ft_swap(&(stack->data), &(stack->next->data));
}

int	bottom(t_node *stack)
{
	while (stack->next)
		stack = stack->next;
	return (stack->data);
}

int	stack_len(t_node *stack)
{
	int	len;

	len = 0;
	while (stack)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}
