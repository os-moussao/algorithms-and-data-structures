/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_parentheses.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussaoui040@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 11:54:28 by os-moussao        #+#    #+#             */
/*   Updated: 2021/09/10 17:44:31 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	arr_append(char **arr, char *str)
{
	int i;

	i = 0;
	while (arr[i] && i < 5)
		i++;
	strcpy(arr[i], str);
}

int	is_valid_str(char **arr, char *str)
{
	for (int i = 0; i < 5; i++)
	{
		if (strcmp(arr[i], str) == 0)
			return (0);
	}
	return (1);
}

void	gen_parentheses(char	**arr, char *str, int op, int cl)
{
	int i = 6 - op - cl;

	if (i != 6)
	{
		while (op)
			str[i++] = '(', op--;
		while (cl)
			str[i++] = ')', cl--;
		//if (is_valid)
		gen_parentheses(arr, str, op, cl);
	}
	else
	{

	}
}

char	**gen_ans(void)
{
	char	**arr;
	char	*str;

	str = calloc(7, sizeof(char));
	arr = malloc(5 * sizeof(char *));
	for (int i = 0; i < 5; i++)
		arr[i] = calloc(7, sizeof(char));
	gen_parentheses(arr, str, 3, 3);
	free(str);
	return (arr);
}

int	main(void)
{
	char **arr;

	arr = gen_ans();
	for (int i = 0; i < 5; i++)
		printf("%s\n", arr[i]),
		free(arr[i]);
	free(arr);
}
