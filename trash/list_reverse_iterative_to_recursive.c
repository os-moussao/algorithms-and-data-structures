/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_reverse_iterative_to_recursive.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussao@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 12:45:05 by os-moussao        #+#    #+#             */
/*   Updated: 2021/10/08 16:41:06 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../list.h"

/**
 * This is just translating the code from the iterative method to recursion
 * Nothing creative!
 * See: tail recursion and head recursion
*/
void	list_reverse_recursive(t_node **head, t_node *prev, t_node *current, t_node *next)
{
	if (!current)
	{
		*head = prev;
		return ;
	}
	next = current->next;
	current->next = prev;
	prev = current;
	current = next;
	list_reverse_recursive(head, prev, current, next);
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
	list_reverse_recursive(&head, NULL, head, NULL);
	list_display(head);

	while (head)
	{
		to_free = head;
		head = head->next;
		free(to_free);
	}
}
