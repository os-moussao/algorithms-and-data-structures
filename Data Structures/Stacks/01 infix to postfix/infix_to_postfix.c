/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infix_to_postfix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussao@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 20:48:21 by os-moussao        #+#    #+#             */
/*   Updated: 2021/10/30 13:16:24 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../stack.h"
#include "../stack_utils.c"

int	precedence(char op)
{
	if (op == '^')
		return (3);
	else if (op == '*' || op == '/')
		return (2);
	else
		return (1);
}

bool	is_op(char c)
{
	return (c == '^' || c == '*' || c == '/' || c == '+' || c == '-');
}

/**
 * todo: parentheses handling
 **/
char	*convert(char *exp)
{
	t_node	*stack = NULL;
	char	*postfix = malloc(strlen(exp));
	int		i = 0;

	while (*exp)
	{
		if (*exp != ' ')
		{
			if (!is_op(*exp))
				postfix[i++] = *exp;
			else
			{
				if (!stack || precedence(*exp) > precedence(*(char *)(stack->data)))
					stack_push(&stack, exp, 1);
				else
				{
					while (stack && precedence(*exp) <= precedence(*(char *)(stack->data)))
						postfix[i++] = *(char *)(stack->data),
						stack_pop(&stack);
					stack_push(&stack, exp, 1);
				}
			}
		}
		exp++;
	}
	while (stack)
	{
		postfix[i++] = *(char *)(stack->data);
		stack_pop(&stack);
	}
	postfix[i] = '\0';
	return (postfix);
}

int	main(void)
{
	char	expression[250];
	char	*postfix;

	printf("Enter an infix expression: ");
	scanf(" %[^\n]", expression);

	postfix = convert(expression);
	printf("expression to postfix: %s\n", postfix);
	free(postfix);
}
