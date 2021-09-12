/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku_solver.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussaoui040@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 17:28:00 by os-moussao        #+#    #+#             */
/*   Updated: 2021/09/12 18:10:12 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

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
    sq_r = (row < 6)? (row < 3)? 0: 3: 6;
    sq_c = (col < 6)? (col < 3)? 0: 3: 6;

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

void    backtrack(char board[][9], int row, int col)
{
    if (board[row][col] == '.')
    {
        for (char choice = '1'; choice <= '9'; choice++)
        {
            if (valid_choice(board, row, col, choice))
                board[row][col] = choice;
        }
    }

	if (row == 8 && col == 8)
		return ;
	else if (col == 8)
    	backtrack(board, row + 1, 0);
	else
		backtrack(board, row, col + 1);
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

	backtrack(board, 0, 0);

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; i < 9; j++)
			printf("%c ", board[i][j]);
		printf("\n");
	}
}
