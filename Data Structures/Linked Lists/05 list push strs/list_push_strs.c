/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_push_strs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussao@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 21:55:47 by os-moussao        #+#    #+#             */
/*   Updated: 2021/10/07 22:34:27 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	list_push_front(t_node **head, char *data)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	node->data = strdup(data);
	node->next = (*head);
	(*head) = node;
}

t_node	*list_push_strs(int size, char **strs)
{
	t_node	*list;

	list = NULL;
	while (size--)
		list_push_front(&list, strs[size]);
	return (list);
}

int	main(int argc, char **argv)
{
	t_node	*list, *to_free;

	list = list_push_strs(argc - 1, argv + 1);
	while (list)
	{
		printf("%s\n", list->data);
		to_free = list;
		list = list->next;
		free(to_free->data);
		free(to_free);
	}
}
