/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussao@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 12:13:17 by os-moussao        #+#    #+#             */
/*   Updated: 2021/10/22 22:55:13 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Testing
**/

#include "../list.h"

void	list_merge(t_node **list1, t_node *list2);

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

int	main(void)
{
	t_node	*list1 = NULL;
	t_node	*list2 = NULL;

	list_push_front(&list1, 0);
	list_push_front(&list1, 1);
	list_push_front(&list1, 2);
	list_push_front(&list1, 3);
	list_push_front(&list1, 4);
	list_push_front(&list1, 5);

	list_push_front(&list2, 16);
	list_push_front(&list2, 17);
	list_push_front(&list2, 18);
	list_push_front(&list2, 19);
	list_push_front(&list2, 20);

	printf("list-1:\n");
	list_display(list1);
	printf("list-2:\n");
	list_display(list2);

	
	printf("merging in list-1:\n");
	list_merge(&list1, list2);
	list_display(list1);

	t_node	*to_free;
	while (list1)
	{
		to_free = list1;
		list1 = list1->next;
		free(to_free);
	}
}
