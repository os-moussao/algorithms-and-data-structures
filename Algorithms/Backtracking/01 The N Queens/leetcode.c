/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leetcode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussaoui040@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 15:47:53 by os-moussao        #+#    #+#             */
/*   Updated: 2021/09/13 21:59:45 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Not accepted yet, idk why

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int	is_valid_choice(int *stack, int col, int choice)
{
	int	diff;

	for (int i = 0; i < col; i++)
	{
		diff = col - i;
		if (stack[i] == choice || diff == abs(stack[i] - choice))
			return (0);
	}
	return (1);
}

void	append_sol(char ****res, int *stack, int N, int len)
{
	// 1 extra spot for the new solution
	(*res) = realloc(*res, (len + 1) * sizeof(char **));
	(*res)[len] = NULL;
	
	// Allocating the new solution 
	(*res)[len  - 1] = malloc(N * sizeof(char *));
	for (int i = 0; i < N; i++)
	{
		(*res)[len - 1][i] = malloc(N);
		for (int j = 0; j < N; j++)
			(*res)[len - 1][i][j] = (stack[i] == j)? 'Q': '.';
	}
}

void	backtrack(int N, int *stack, int col, char	****res, int *len)
{
	if (col == N)
	{
		(*len)++;
		append_sol(res, stack, N, *len);
		return ;
	}

	for (int choice = 0; choice < N; choice++)
	{
		if (is_valid_choice(stack, col, choice))
		{
			stack[col] = choice;
			backtrack(N, stack, col + 1, res, len);
		}
	}
}

char    ***solveNQueens(int N, int *solution_count, int **col_sizes)
{
	char	***res;
	int		stack[N];
	int		len;

	res = calloc(1, sizeof(char **));

    *solution_count = 0;
	backtrack(N, stack, 0, &res, solution_count);
    
    (*col_sizes) = malloc((*solution_count) * sizeof(int));
    for (int i = 0; i < *solution_count; i++)
        (*col_sizes)[i] = N;

	return (res);
}

int	main(int argc, char **argv)
{
	int	*cs;
	int	r;
	char	***res;

	res = solveNQueens(atoi(argv[1]), &r, &cs);
	printf("r: %d\n", r);
	for (int i = 0; i < r; i++)
		printf("%d\n", cs[i]);
}
