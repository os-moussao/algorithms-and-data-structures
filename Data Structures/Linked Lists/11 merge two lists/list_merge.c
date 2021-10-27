/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_merge.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussao@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 21:09:28 by os-moussao        #+#    #+#             */
/*   Updated: 2021/10/27 21:59:35 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../list.h"

t_node	*list_merge(t_node *list1, t_node *list2)
{
	if (!list1)
		return (list2);
	if (!list2)
		return (list1);

	t_node	*list = NULL;
	if (list1->data < list2->data)
		list = list1, list1 = list1->next;
	else
		list = list2, list2 = list2->next;
	t_node	*head = list;
	while (list1 && list2)
	{
		if (list1->data < list2->data)	// 2 8 10 15 -- 4 7 12 14
		{
			head->next = list1;
			list1 = list1->next;
		}
		else
		{
			head->next = list2;
			list2 = list2->next;
		}
		head = head->next;
	}
	while (list1)
	{
		head->next = list1;
		list1 = list1->next;
	}
	while (list2)
	{
		head->next = list2;
		list2 = list2->next;
	}
	return (list);
}
