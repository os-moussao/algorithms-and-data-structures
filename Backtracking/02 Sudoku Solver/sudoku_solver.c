/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku_solver.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussaoui040@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 17:28:00 by os-moussao        #+#    #+#             */
/*   Updated: 2021/09/12 23:11:34 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		can_ch(int row, int col)
{
	char	board[9][9] = 
	{
		{'5','3','.','.','7','.','.','.','.'},
		{'6','.','.','1','9','5','.','.','.'},
		{'.','9','8','.','.','.','.','6','.'},
		{'8','.','.','.','6','.','.','.','3'},
		{'4','.','.','8','.','3','.','.','1'},
		{'7','.','.','.','2','.','.','.','6'},
		{'.','6','.','.','.','.','2','8','.'},
		{'.','.','.','4','1','9','.','.','5'},
		{'.','.','.','.','8','.','.','7','9'}
	};

	return (board[row][col] == '.');
}

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

void    backtrack(char board[][9], int row, int col, int can_change)
{
	//int	val;

	if (row == 9)
		return ;

	if (board[row][col] != '.')
	{
		if (col == 8)
    		backtrack(board, row + 1, 0, 0);
		else
			backtrack(board, row, col + 1, 0);
	}

	//val = can_ch(row, col);
	/*
	if (!can_change)
	{
		if (col == 0)
			printf("bd[%d][%d]: %c\n", row - 1, 8, board[row - 1][8]);
		else
			printf("bd[%d][%d]: %c\n", row, col - 1, board[row][col - 1]);

	}
	*/
	
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
	char	board[9][9] = 
	{
		{'5','3','.','.','7','.','.','.','.'},
		{'6','.','.','1','9','5','.','.','.'},
		{'.','9','8','.','.','.','.','6','.'},
		{'8','.','.','.','6','.','.','.','3'},
		{'4','.','.','8','.','3','.','.','1'},
		{'7','.','.','.','2','.','.','.','6'},
		{'.','6','.','.','.','.','2','8','.'},
		{'.','.','.','4','1','9','.','.','5'},
		{'.','.','.','.','8','.','.','7','9'}
	};

	put_board(board);

	backtrack(board, 0, 0, 1);
	printf("\nResult:\n");
	put_board(board);
}
