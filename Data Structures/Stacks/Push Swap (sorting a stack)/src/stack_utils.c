/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:47:51 by omoussao          #+#    #+#             */
/*   Updated: 2021/12/13 22:29:05 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_push(t_node **stack, int data)
{
	t_node	*new = (t_node *)malloc(sizeof(t_node));
	new->data = data;
	new->next = (*stack);
	(*stack) = new;
}

int	stack_pop(t_node **stack)
{
	int ret;

	ret = (*stack)->data;
	t_node	*to_free = *stack;
	*stack = (*stack)->next;
	free(to_free);
	return (ret);
}

void	stack_clear(t_node **stack)
{
	while (*stack)
		stack_pop(stack);
}
