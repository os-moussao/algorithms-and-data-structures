/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku_solver.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussaoui040@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 17:28:00 by os-moussao        #+#    #+#             */
/*   Updated: 2021/09/13 12:25:00 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>

int     valid_choice(char bd[][9], int row, int col, char choice)
{
    int sq_r, sq_c;

    // Col check
    for (int i = 0; i < 9; i++)
    {
        if (bd[row][i] == choice)
            return (0);
    }
    
    // Row check
    for (int i = 0; i < 9; i++)
    {
        if (bd[i][col] == choice)
            return (0);
    }
    
    // Square check
    sq_r = (row < 6)? (row < 3)? 0: 3: 6; // to be changed
    sq_c = (col < 6)? (col < 3)? 0: 3: 6; // to be changed

    for (int i = sq_r; i < sq_r + 3; i++)
    {
        for (int j = sq_c; j < sq_c + 3; j++)
        {
            if (bd[i][j] == choice)
		          return (0);
        }
    }
    
    return (1);
}

int	next_pos(char board[][9], int *row, int *col)
{
	for (; (*row) < 9; (*row)++)
	{
		for (; (*col) < 9; (*col)++)
		{
			if (board[*row][*col] == '.')
				return (0);
		}
		(*col) = 0;
	}
	return (1);
}

bool	solve_sudoku(char board[][9], int row, int col)
{
	int solved = next_pos(board, &row, &col);

	if (solved)
		return (true);

	for (char choice = '1'; choice <= '9'; choice++)
	{
        if (valid_choice(board, row, col, choice))
		{
            board[row][col] = choice;

			// Backtracking
			if (solve_sudoku(board, row, col))
				return (true);

			board[row][col] = '.';
		}
	}

	return (false);
}

void	put_board(char board[][9])
{
	for (int i = 0; i < 9; i++)
	{
		if (i && i % 3 == 0)
			printf("\n");
		for (int j = 0; j < 9; j++)
		{
			if (j && j % 3 == 0)
				printf(" ");
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}

int	main(void)
{
	char	puzzle[9][9];

	scanf(" %[^\n]%*c", puzzle[0]);
	scanf(" %[^\n]%*c", puzzle[1]);
	scanf(" %[^\n]%*c", puzzle[2]);
	scanf(" %[^\n]%*c", puzzle[3]);
	scanf(" %[^\n]%*c", puzzle[4]);
	scanf(" %[^\n]%*c", puzzle[5]);
	scanf(" %[^\n]%*c", puzzle[6]);
	scanf(" %[^\n]%*c", puzzle[7]);
	scanf(" %[^\n]%*c", puzzle[8]);

	printf("\nBefore:\n");
	put_board(puzzle);
	
	solve_sudoku(puzzle, 0, 0);

	printf("\n\nResult:\n");
	put_board(puzzle);
}

/*

How I tried to solve this problem before:

void    backtrack(char board[][9], int row, int col, int can_change)
{
	if (row == 9)
		return ;

	if (board[row][col] != '.')
	{
		if (col == 8)
    		backtrack(board, row + 1, 0, 0);
		else
			backtrack(board, row, col + 1, 0);
	}

    if (board[row][col] == '.')
    {
        for (char choice = '1'; choice <= '9'; choice++)
        {
            if (valid_choice(board, row, col, choice))
			{
                board[row][col] = choice;
				if (col == 8)
			    	backtrack(board, row + 1, 0, 1);
				else
					backtrack(board, row, col + 1, 1);
			}
        }

		if (board[row][col] == '.')
		{
			if (can_change)
			{
				if (col == 0)
					board[row - 1][8] = '.';
				else
					board[row][col - 1] = '.';
			}
			return ;
		}
    }

	if (col == 8)
    	backtrack(board, row + 1, 0, 1);
	else
		backtrack(board, row, col + 1, 1);
}
*/
