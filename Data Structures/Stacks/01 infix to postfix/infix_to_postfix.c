/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infix_to_postfix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussao@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 20:48:21 by os-moussao        #+#    #+#             */
/*   Updated: 2021/10/29 23:30:30 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../stack.h"
#include "../stack_utils.c"

int	main(void)
{
	t_node	*stack = NULL;
	int		n = 1337;

	stack_push(&stack, &n, sizeof(n));
	printf("%d\n", *(int *)stack->data);
	stack_clear(&stack);
}
