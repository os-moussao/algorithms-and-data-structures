/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 21:32:25 by omoussao          #+#    #+#             */
/*   Updated: 2021/12/13 23:24:09 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct s_node
{
	int				data;
	struct s_node	*next;
}				t_node;

void	ft_swap(int *a, int *b);

void	push(t_node **stack, int data);
int		pop(t_node **stack);
void	swap(t_node *stack);
void	clear(t_node **stack);
void	rotate(t_node *stack);
void	rrotate(t_node *stack);

#endif
