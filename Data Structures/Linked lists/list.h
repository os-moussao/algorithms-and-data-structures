/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussao@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 11:17:12 by os-moussao        #+#    #+#             */
/*   Updated: 2021/10/07 20:28:12 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
#define LIST_H

# include <stdio.h>
# include <stdlib.h>

typedef struct	s_node
{
	int				data;
	struct s_node	*next;
}				t_node;

#endif
