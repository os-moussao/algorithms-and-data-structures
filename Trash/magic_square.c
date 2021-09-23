/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magic_square.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussaoui040@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 23:01:15 by os-moussao        #+#    #+#             */
/*   Updated: 2021/09/23 12:42:45 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * A magic square is a square where the sums of the numbers in each row, each column, and both main diagonals are the same.
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int	magic_square(int n);

int	main(int argc, char **argv)
{
	int	sum;

	if (argc != 2)
	{
		printf("Usage: ./program [N]");
		return (1);
	}
	sum = magic_square(atoi(argv[1]));
	printf("\n\nSum: %d\n", sum);
}

int		**init_msq(int n);
void	put_msq(int	**msq, int n);
bool	is_magic_sq(int **msq, int n);
bool	find_next_pos(int **msq, int n, int *row, int *col);
bool	backtrack(int **msq, int n, int row, int col);

int	magic_square(int n)
{
	int	**msq;

	msq = init_msq(n);
	//put_msq(msq, n);
	backtrack(msq, n, 0, 0);
	put_msq(msq, n);
	return (n * (n * n + 1) / 2);
}

bool	backtrack(int **msq, int n, int row, int col)
{
	if (!find_next_pos(msq, n, &row, &col))
	{
		if (is_magic_sq(msq, n))
			return (true);
		else
			return (false);
	}

	for (int choice = 1; choice <= n * n; choice++)
	{
		msq[row][col] = choice;
		if (backtrack(msq, n, row, col))
			return (true);
	}
	msq[row][col] = 0;
}

bool	is_magic_sq(int **msq, int n)
{
	int	sum, m_sum, i, j;

	// 	Magic sum
	m_sum = n * (n * n + 1) / 2;

	// Rows check
	for (i = 0; i < n; i++)
	{
		sum = 0;
		for (j = 0; j < n; j++)
			sum += msq[i][j];
		if (sum != m_sum)
			return (false);
	}

	// Cols check
	for (j = 0; j < n; j++)
	{
		sum = 0;
		for (i = 0; i < n; i++)
			sum += msq[i][j];
		if (sum != m_sum)
			return (false);
	}

	// Diag1 check
	sum = 0;
	for (i = 0; i < n; i++)
		sum += msq[i][i];
	if (sum != m_sum)
			return (false);

	// Diag2 check
	sum = 0;
	for (i = 0; i < n; i++)
		sum += msq[i][n - i - 1];
	if (sum != m_sum)
			return (false);

	// If all tests are passed, then it's valid
	return (true);
}

bool	find_next_pos(int **msq, int n, int *row, int *col)
{
	for (; *row < n; (*row)++)
	{
		for (; *col < n; (*col)++)
		{
			if (!msq[*row][*col])
				return (true);
		}
		*col = 0;
	}
	return (false);
}

int	**init_msq(int n)
{
	int	**msq;

	msq = malloc(n * sizeof(int *));
	for (int i = 0; i < n; i++)
		msq[i] = calloc(n, sizeof(int));
	return (msq);
}

void	put_msq(int	**msq, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			printf("%d ", msq[i][j]);
		printf("\n");
		free(msq[i]);
	}
	free(msq);
}
