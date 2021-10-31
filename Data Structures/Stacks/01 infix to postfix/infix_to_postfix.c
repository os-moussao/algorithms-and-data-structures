/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infix_to_postfix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussao@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 20:48:21 by os-moussao        #+#    #+#             */
/*   Updated: 2021/10/31 23:57:37 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../stack.h"
#include "../stack_utils.c"

int	precedence(char op)
{
	switch (op)
	{
		case '^':
			return 3;
		case '*':
		case '/':
			return 2;
		case '+':
		case '-':
			return 1;
	}
}

bool has_higher_prec(char op1, char op2)
{
	int p1 = precedence(op1);
	int p2 = precedence(op2);

	if (p1 == p2)
		return (op1 != '^');
	return p1 > p2;
}

bool	is_operator(char c)
{
	return (c == '^' || c == '*' || c == '/' || c == '+' || c == '-');
}

char	*infix_to_postfix(char *exp)
{
	t_node	*stack = NULL;
	char	*postfix = malloc(strlen(exp));
	int		i = 0;

	while (*exp)
	{
		if (*exp != ' ')
		{
			exp++;
			continue ;
		}

		if (*exp == '(')
			stack_push(&stack, exp, 1);
		else if (*exp == ')')
		{
			// pop from stack until finding an opening parenthese or the stack is empthy
			while (stack && *(char *)(stack->data) != '(')
				postfix[i++] = *(char *)(stack->data),
				stack_pop(&stack);
			if (stack)
				stack_pop(&stack);
		}
		else if (is_operator(*exp))
		{
			if (!stack || *(char *)(stack->data) == '(' || has_higher_prec(*exp, *(char *)(stack->data)))
				stack_push(&stack, exp, 1);
			else
			{
				while (stack && *(char *)(stack->data) != '(' && !has_higher_prec(*exp, *(char *)(stack->data)))
					postfix[i++] = *(char *)(stack->data),
					stack_pop(&stack);
				stack_push(&stack, exp, 1);
			}
		}
		else // an operand
			postfix[i++] = *exp;
		exp++;
	}
	while (stack)
	{
		if (is_operator(*(char *)(stack->data)))
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

	postfix = infix_to_postfix(expression);
	printf("expression to postfix: %s\n", postfix);
	free(postfix);
}
