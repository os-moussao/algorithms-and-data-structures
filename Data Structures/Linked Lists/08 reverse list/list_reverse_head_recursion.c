/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_reverse_head_recursion.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussao@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:04:31 by os-moussao        #+#    #+#             */
/*   Updated: 2021/10/09 12:22:38 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../list.h"

/**
 * This is list_reverse using head recursion method, where the function will:
 * - traverse till the end of the list
 * - update head of the list to point to the last element
 * - and then starts to manipulate the pointers backwards
**/
void	list_reverse_head_recursion(t_node **head, t_node *prev)
{
	t_node	*head_tmp;

	if (!*head)
	{
		*head = prev;
		return ;
	}
	head_tmp = *head;
	*head = (*head)->next;
	list_reverse_head_recursion(head, head_tmp);
	head_tmp->next = prev;
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
	list_reverse_head_recursion(&head, NULL);
	list_display(head);

	while (head)
	{
		to_free = head;
		head = head->next;
		free(to_free);
	}
}
