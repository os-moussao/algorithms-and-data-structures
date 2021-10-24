/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_parentheses.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussaoui040@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 11:25:47 by os-moussao        #+#    #+#             */
/*   Updated: 2021/09/11 13:10:23 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	append_sol(char ***arr, char *str, int n, int arr_len)
{
	*arr = realloc(*arr, (arr_len + 1) * sizeof(char *));
	(*arr)[arr_len] = NULL;
	(*arr)[arr_len - 1] = malloc((2 * n + 1) * sizeof(char));
	strcpy((*arr)[arr_len - 1], str);
}

void	backtrack(char ***arr, char *stack, int op, int cl, int n, int *arr_len)
{
	int		i = op + cl;

	if (i == 2 * n)
	{
		append_sol(arr, stack, n, *arr_len);
		(*arr_len)++;
		return ;
	}

	if (op < n)
	{
		stack[i] = '(';
		backtrack(arr, stack, op + 1, cl, n, arr_len);
	}

	if (cl < op)
	{
		stack[i] = ')';
		backtrack(arr, stack, op, cl + 1, n, arr_len);
	}
}

char	**generate_parentheses(int n)
{
	char	**arr;
	char	stack[2 * n + 1];
	int		arr_len;

	arr = malloc(1 * sizeof(char *));
	arr[0] = NULL;

	stack[2 * n] = 0;
	arr_len = 1;
	backtrack(&arr, stack, 0, 0, n, &arr_len);
	return (arr);
}

int	main(void)
{
	char	**arr;

	arr = generate_parentheses(8);
	for (int i = 0; arr[i]; i++)
	{
		printf("%s\n", arr[i]);
		free(arr[i]);
	}
	free(arr);
}
