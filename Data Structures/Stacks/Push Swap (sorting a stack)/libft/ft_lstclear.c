/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 13:13:15 by omoussao          #+#    #+#             */
/*   Updated: 2021/11/04 13:15:42 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*to_free;

	while (*lst)
	{
		to_free = *lst;
		*lst = (*lst)->next;
		ft_lstdelone(to_free, del);
	}
}
