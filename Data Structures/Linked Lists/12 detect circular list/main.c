/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussao@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 12:13:17 by os-moussao        #+#    #+#             */
/*   Updated: 2021/10/27 22:29:51 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Testing
**/

#include "../list.h"
#include <stdbool.h>

// prototype
bool	is_circular(t_node *list);

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

	list_push_front(&list1, 0);
	list_push_front(&list1, 1);
	list_push_front(&list1, 2);
	list_push_front(&list1, 3);
	list_push_front(&list1, 4);
	list_push_front(&list1, 5);
	
	// making list1 circular
	t_node	*head = list1;
	while (head->next)
		head = head->next;
	head->next = list1;

	list_push_front(&list2, 0);
	list_push_front(&list2, 0);
	list_push_front(&list2, 0);
	list_push_front(&list2, 0);
	list_push_front(&list2, 0);

	printf("list1 is%scircular\n", is_circular(list1)?" ":" not ");
	printf("list2 is%scircular\n", is_circular(list2)?" ":" not ");
}
