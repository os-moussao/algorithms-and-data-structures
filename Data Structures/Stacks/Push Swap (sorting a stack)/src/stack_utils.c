/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:47:51 by omoussao          #+#    #+#             */
/*   Updated: 2021/12/14 02:07:39 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node *stack)
{
	if (stack->next)
		ft_swap(&(stack->data), &(stack->next->data));
}

void	push(t_node **stack, int data)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		error();
	new->data = data;
	new->next = (*stack);
	(*stack) = new;
}

int	pop(t_node **stack)
{
	t_node	*to_free;
	int		ret;

	ret = (*stack)->data;
	to_free = *stack;
	*stack = (*stack)->next;
	free(to_free);
	return (ret);
}

void	clear(t_node **stack)
{
	while (*stack)
		pop(stack);
}
