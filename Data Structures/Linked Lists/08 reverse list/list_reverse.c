/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_reverse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussao@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 00:08:11 by os-moussao        #+#    #+#             */
/*   Updated: 2021/11/10 10:34:27 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../list.h"

void	list_reverse(t_node **head)
{
	t_node	*prev, *current, *next;

	prev = NULL;
	current = *head;
	while (current)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*head = prev;
}


/**
 * Testing...
**/
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
	list_push_front(&head, 3);
	list_push_front(&head, 4);
	list_push_front(&head, 5);
	list_push_front(&head, 6);
	list_push_front(&head, 7);
	list_push_front(&head, 8);
	list_push_front(&head, 9);

	printf("List:\n");
	list_display(head);
	printf("\nList reversed:\n");
	list_reverse(&head);
	list_display(head);

	while (head)
	{
		to_free = head;
		head = head->next;
		free(to_free);
	}
}
