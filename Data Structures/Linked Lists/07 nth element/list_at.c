/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_at.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussao@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 23:47:58 by os-moussao        #+#    #+#             */
/*   Updated: 2021/10/08 00:02:44 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../list.h"

t_node	*list_at(t_node *head, unsigned int index)
{
	while (index && head)
	{
		head = head->next;
		index--;
	}
	return (index? NULL: head);
}
