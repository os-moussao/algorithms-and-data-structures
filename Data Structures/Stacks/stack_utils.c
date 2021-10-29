/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussao@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 21:24:37 by os-moussao        #+#    #+#             */
/*   Updated: 2021/10/29 23:42:56 by os-moussao       ###   ########.fr       */
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
/* alternative process for memcpy */
// for (int i = 0; i < data_size; i++)
// 	*(char *)(new->data + i) = *(char *)(data + i);

void	stack_pop(t_node **stack)
{
	t_node	*to_free = *stack;
	*stack = (*stack)->next;
	free(to_free->data);
	free(to_free);
}

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
