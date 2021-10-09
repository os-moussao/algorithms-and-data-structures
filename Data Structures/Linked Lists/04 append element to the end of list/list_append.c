/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_append.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussao@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 21:17:04 by os-moussao        #+#    #+#             */
/*   Updated: 2021/10/07 21:30:41 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../list.h"

void	list_append(t_node **head, int data)
{
	t_node	*new, *ptr;

	new = malloc(sizeof(t_node));
	new->data = data;
	new->next = NULL;
	if (!(*head))
		(*head) = new;
	else
	{
		ptr = *head;
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = new;
	}
}

int	main(void)
{
	t_node	*head, *to_free;

	head = NULL;
	list_append(&head, 10);
	list_append(&head, 20);
	list_append(&head, 30);
	list_append(&head, 40);
	list_append(&head, 50);
	list_append(&head, 60);
	while (head)
	{
		printf("%d\n", head->data);
		to_free = head;
		head = head->next;
		free(to_free);
	}
}
