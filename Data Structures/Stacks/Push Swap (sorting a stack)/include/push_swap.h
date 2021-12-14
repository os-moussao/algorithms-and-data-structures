/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 21:32:25 by omoussao          #+#    #+#             */
/*   Updated: 2021/12/14 01:50:32 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

# define I_MAX 2147483647
# define I_MIN -2147483648

typedef struct s_node
{
	int				data;
	struct s_node	*next;
}				t_node;

void	ft_swap(int *a, int *b);
void	error(void);

t_node	*create(char **av, int ac);
void	push(t_node **stack, int data);
int		pop(t_node **stack);
void	swap(t_node *stack);
void	clear(t_node **stack);
void	rotate(t_node *stack);
void	rrotate(t_node *stack);
int		top(t_node *stack);

#endif
