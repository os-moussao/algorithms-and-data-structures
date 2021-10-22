/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_merge.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussao@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 22:31:04 by os-moussao        #+#    #+#             */
/*   Updated: 2021/10/22 22:51:26 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../list.h"

// Place elements of list2 at the end of list1
// element creation is not authorized
// only pointer manipulation
void	list_merge(t_node **list1, t_node *list2)
{
	if (!*list1)
	{
		*list1 = list2;
		return ;
	}

	t_node	*ptr = *list1;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = list2;
}
