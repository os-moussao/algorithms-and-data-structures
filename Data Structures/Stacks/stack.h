/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussao@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 21:19:30 by os-moussao        #+#    #+#             */
/*   Updated: 2021/10/29 22:00:40 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_node
{
	void			*data;
	struct s_node	*next;
}				t_node;

void stack_push(t_node **stack, void *data, size_t data_size);
void stack_pop(t_node **stack);
void stack_clear(t_node **stack);

#endif
