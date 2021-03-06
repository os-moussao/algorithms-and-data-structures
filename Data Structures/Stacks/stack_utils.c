/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussao@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 21:24:37 by os-moussao        #+#    #+#             */
/*   Updated: 2021/11/01 21:45:50 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	stack_push(t_node **stack, void *data, size_t data_size)
{
	t_node	*new = (t_node *)malloc(sizeof(t_node));
	new->data = malloc(data_size);
	memcpy(new->data, data, data_size);
	new->next = (*stack);
	(*stack) = new;
}

void	stack_pop(t_node **stack)
{
	t_node	*to_free = *stack;
	*stack = (*stack)->next;
	free(to_free->data);
	free(to_free);
}

void	stack_clear(t_node **stack)
{
	while (*stack)
		stack_pop(stack);
}

/*
void	stack_clear(t_node **stack)
{
	t_node	*to_free;

	while (*stack)
	{
		to_free = *stack;
		*stack = (*stack)->next;
		free(to_free->data);
		free(to_free);
	}
}
*/
