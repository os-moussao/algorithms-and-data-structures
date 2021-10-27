/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_circular.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussao@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 22:10:03 by os-moussao        #+#    #+#             */
/*   Updated: 2021/10/27 22:31:58 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../list.h"
#include <stdbool.h>

bool	is_circular(t_node *list)
{
	if (!list)
		return (false);

	t_node	*p, *q;
	p = q = list;
	while (p->next && q->next && q->next->next)
	{
		p = p->next;
		q = q->next->next;
		if (p == q)
			return (true);
	}
	return (false);
}
