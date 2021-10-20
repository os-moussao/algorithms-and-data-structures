/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_remove_if_recursive.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussao@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 12:10:27 by os-moussao        #+#    #+#             */
/*   Updated: 2021/10/20 12:20:47 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../list.h"

void	list_remove_if(t_node **head, int data_ref)
{
	t_node	*to_free;

	if (*head)
	{
		if ((*head)->data == data_ref)
		{
			to_free = *head;
			(*head) = (*head)->next;
			free(to_free);
			list_remove_if(head, data_ref);
		}
		else
			list_remove_if(&(*head)->next, data_ref);
	}
}
