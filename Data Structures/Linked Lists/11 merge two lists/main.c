/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussao@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 12:13:17 by os-moussao        #+#    #+#             */
/*   Updated: 2021/10/27 21:56:13 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Testing
**/

#include "../list.h"

// prototype
t_node	*list_merge(t_node *list1, t_node *list2);

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
	t_node	*list1 = NULL;
	t_node	*list2 = NULL;

	list_push_front(&list1, 15);
	list_push_front(&list1, 10);
	list_push_front(&list1, 8);
	list_push_front(&list1, 2);

	list_push_front(&list2, 14);
	list_push_front(&list2, 12);
	list_push_front(&list2, 7);
	list_push_front(&list2, 4);

	printf("list1:\n");
	list_display(list1);

	printf("list2:\n");
	list_display(list2);

	list1  = list_merge(list1, list2);
	printf("merged:\n");
	list_display(list1);

	free_list(&list1);
}
