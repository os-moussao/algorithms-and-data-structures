/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussao@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 23:24:00 by os-moussao        #+#    #+#             */
/*   Updated: 2021/10/07 23:45:35 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../list.h"

void	list_clear(t_node **head)
{
	t_node	*to_free;

	while (*head)
	{
		to_free = *head;
		*head = *head->next;
		free(to_free);
	}
	*head = NULL;
}
