/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_n_queens_puzzle_visual.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussaoui040@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 12:58:24 by os-moussao        #+#    #+#             */
/*   Updated: 2021/09/13 15:15:46 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

// You can try the solutions on this site: https://www.datagenetics.com/blog/august42012/
// or try this N Queens app: https://play.google.com/store/apps/details?id=com.ggwp.nqueens&hl=en_US&gl=US

void	putnstr(char *str, int n)
{
	for (int i = 0; i < n; i++)
		printf("%c", str[i]);
	printf("\n");
}

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

char	***the_n_queens(int N, int *solution_count)
{
	char	***res;
	int		stack[N];
	int		len;

	res = calloc(1, sizeof(char **));
	*solution_count = 0;

	backtrack(N, stack, 0, &res, solution_count);
	return (res);
}

int	main(int argc, char **argv)
{
	char	***res;
	int		solution_count;
	int		N;

	if (argc != 2)
	{
		printf("Usage: ./program [1 <= N <= 12]");
		return (1);
	}

	N = atoi(argv[1]);
	if (N < 1 || N > 12)
	{
		printf("Usage: ./program [1 <= N <= 12]");
		return (2);
	}

	res = the_n_queens(N, &solution_count);
	for (int s = 0; s < solution_count; s++)
	{
		printf("Solution #%d:\n", s + 1);
		for (int i = 0; i < N; i++)
			putnstr(res[s][i], N),
			free(res[s][i]);
		printf("\n");
		free(res[s]);
	}

	free(res);
	printf("Total Solutions: %d\n", solution_count);
}
