/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_element.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussao@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 19:51:02 by os-moussao        #+#    #+#             */
/*   Updated: 2021/10/07 20:21:47 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../list.h"

t_node	*list_last(t_node *head)
{
	if (!head)
		return (head);
	while (head->next)
		head = head->next;
	return (head);
}
