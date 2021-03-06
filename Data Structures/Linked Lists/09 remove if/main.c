/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussao@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 12:13:17 by os-moussao        #+#    #+#             */
/*   Updated: 2021/10/20 12:18:47 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Testing
**/

#include "../list.h"

void	list_remove_if(t_node **head, int data_ref);

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
	t_node	*head;
	t_node	*to_free;

	head = NULL;
	list_push_front(&head, 0);
	list_push_front(&head, 1);
	list_push_front(&head, 2);
	list_push_front(&head, 0);
	list_push_front(&head, 4);
	list_push_front(&head, 5);
	list_push_front(&head, 0);
	list_push_front(&head, 7);
	list_push_front(&head, 8);
	list_push_front(&head, 0);

	printf("List:\n");
	list_display(head);
	printf("\nList without value 0:\n");
	list_remove_if(&head, 0);
	list_display(head);

	while (head)
	{
		to_free = head;
		head = head->next;
		free(to_free);
	}
}
