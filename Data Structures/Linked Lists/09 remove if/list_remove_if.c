/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_remove_if.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussao@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 19:28:33 by os-moussao        #+#    #+#             */
/*   Updated: 2021/10/20 12:14:56 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../list.h"

void	list_remove_if(t_node **head, int data_ref)
{
	t_node	*to_free, *prev, *current;

	// while data_ref exists in the beginning of the list
	while ((*head)->data == data_ref)
	{
		to_free = (*head);
		(*head) = (*head)->next;
		free(to_free);
	}

	if (!(*head))
		return ;

	// if data_ref is in the middle or at the end of the list
	prev = (*head);
	current = (*head)->next;
	while (current)
	{
		if (current->data != data_ref)
		{
			prev = prev->next;
			current = current->next;
		}
		else
		{
			to_free = current;
			current = current->next;
			prev->next = current;
			free(to_free);
		}
	}
}
