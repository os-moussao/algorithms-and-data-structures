/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_n_queens_puzzle.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussaoui040@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 16:44:57 by os-moussao        #+#    #+#             */
/*   Updated: 2021/09/11 19:20:16 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	is_valid_choice(char *stack, int col, char choice)
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

void	backtrack(int N, char *stack, int col, int *count)
{
	if (col == N)
	{
		printf("%s\n", stack);
		(*count)++;
		return ;
	}
	for (char choice = '0'; choice < '0' + N; choice++)
	{
		if (is_valid_choice(stack, col, choice))
		{
			stack[col] = choice;
			backtrack(N, stack, col + 1, count);
		}
	}
}

int	the_n_queens(int N)
{
	char	stack[N + 1];
	int	solution_count = 0;

	stack[N] = 0;
	backtrack(N, stack, 0, &solution_count);
	return (solution_count);
}

int	main(int argc, char **argv)
{
	int	count;

	if (argc != 2)
	{
		printf("Usage: ./program [N]");
		return (1);
	}
	count = the_n_queens(atoi(argv[1]));
	printf("\n\nSolution Count: %d\n", count);
}
