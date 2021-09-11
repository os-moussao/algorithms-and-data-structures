/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_parentheses.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussaoui040@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 20:12:33 by os-moussao        #+#    #+#             */
/*   Updated: 2021/09/11 13:16:39 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// This is the first idea that came to my mind for solving this problem
// it's kind of a brute force solution
//
// there is another solution using backtracking, see: Backtracking Section --> '00 generate parentheses'


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	add_str(char ***arr, int n, char *str, int len)
{
	(*arr) = realloc(*arr, len * sizeof(char *));
	(*arr)[len - 1] = NULL;
	(*arr)[len - 2] = calloc(2 * n + 1, sizeof(char));
	strcpy((*arr)[len - 2], str);
	(*arr)[len - 2][strlen(str)] = ')';
}

void	get_sol(char ***array, int n, int len)
{
	int		i = 0, j = 0, op = n, cl = n;
	char	**arr = *array;

	while (arr[i] && strlen(arr[i]) == 2 * n)
		i++;
	if (arr[i] == NULL)
		return ;
	while (arr[i][j])
	{
		if (arr[i][j] == '(')
			op--;
		else
			cl--;
		j++;
	}
	if (cl > op && op)
		add_str(array, n, arr[i], ++len), arr = *array;
	else if (cl > op)
		arr[i][j] = ')';
	if (op)
		arr[i][j] = '(';
	get_sol(array, n, len);
}

char	**gen_parentheses(int n)
{
	char	**arr;
	
	// starting array
	arr = malloc(2 * sizeof(char *));
	arr[0] = calloc(2 * n + 1, sizeof(char));
	arr[1] = NULL;
	arr[0][0] = '(';

	// filling array with solutions
	get_sol(&arr, n, 2);

	// returning
	return (arr);
}



int	main(void)
{
	char	**arr;

	arr = gen_parentheses(4);
	for (int i = 0; arr[i]; i++)
	{
		printf("%s\n", arr[i]);
		free(arr[i]);
	}
	free(arr);
}
