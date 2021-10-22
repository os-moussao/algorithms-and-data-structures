/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussao@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 12:13:17 by os-moussao        #+#    #+#             */
/*   Updated: 2021/10/22 23:40:58 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Testing
**/

#include "../list.h"

// prototype

void	list_push_front(t_node **head, int data)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	node->data = data;
	node->next = (*head);
	(*head) = node;
}

void	list_display(t_node *head)
{
	while (head)
	{
		printf("%d	", head->data);
		head = head->next;
	}
	printf("\n");
}

void	free_list(t_node **list)
{
	t_node	*to_free;

	while (*list)
	{
		to_free = *list;
		*list = (*list)->next;
		free(to_free);
	}
}

int	main(void)
{
	t_node	*list = NULL;

	list_push_front(&list, 0);
	list_push_front(&list, 1);
	list_push_front(&list, 2);
	list_push_front(&list, 3);
	list_push_front(&list, 4);
	list_push_front(&list, 5);

	printf("list:\n");
	list_display(list);

	printf("list:\n");
	// apply function
	list_display(list);

	free_list(&list);
}
