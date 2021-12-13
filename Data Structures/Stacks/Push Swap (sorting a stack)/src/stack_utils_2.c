/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 23:18:47 by omoussao          #+#    #+#             */
/*   Updated: 2021/12/13 23:22:37 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap"

void	rotate(t_node *stack)
{
	while (stack->next)
		ft_swap(&(stack->data), &(stack->next->data))
}

void	rrotate(t_node *stack)
{
	if (!(stack->next))
		return ;
	rrotate(stack->next);
	ft_swap(&(stack->data), &(stack->next->data));
}
