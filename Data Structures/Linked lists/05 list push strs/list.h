/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussao@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 21:55:06 by os-moussao        #+#    #+#             */
/*   Updated: 2021/10/07 21:59:24 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
#define LIST_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct	s_node
{
	char			*data;
	struct s_node	*next;
}				t_node;

#endif
