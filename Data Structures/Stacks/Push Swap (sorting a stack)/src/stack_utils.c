/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:47:51 by omoussao          #+#    #+#             */
/*   Updated: 2021/12/13 23:03:30 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node *stack)
{
	int	tmp;

	if (stack->next)
	{
		tmp = stack->data;
		stack->data = stack->next->data;
		stack->next->data = tmp;
	}
}

void	push(t_node **stack, int data)
{
	t_node	*new = (t_node *)malloc(sizeof(t_node));
	new->data = data;
	new->next = (*stack);
	(*stack) = new;
}

int	pop(t_node **stack)
{
	int ret;

	ret = (*stack)->data;
	t_node	*to_free = *stack;
	*stack = (*stack)->next;
	free(to_free);
	return (ret);
}

void	clear(t_node **stack)
{
	while (*stack)
		stack_pop(stack);
}
