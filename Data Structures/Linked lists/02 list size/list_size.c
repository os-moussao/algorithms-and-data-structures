/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussao@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 12:01:16 by os-moussao        #+#    #+#             */
/*   Updated: 2021/10/07 12:07:09 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../list.h"

int	list_size(t_node *head)
{
	int	size;

	size = 0;
	while (head)
		head = head->next,
		size++;
	return (size);
}

int	list_size_recursive(t_node *head)
{
	if (!head)
		return (0);
	return (1 + list_size_recursive(head->next));
}
