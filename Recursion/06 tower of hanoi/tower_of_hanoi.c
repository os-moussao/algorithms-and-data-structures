/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tower_of_hanoi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussaoui040@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 17:40:28 by os-moussao        #+#    #+#             */
/*   Updated: 2021/09/14 18:12:39 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	put_move(int from, int to)
{
	printf("%d -> %d\n", from, to);
}

/**
 * this function prints and returns the number of moves
 * to solve a hanoi puzzle
 * test solutions in: https://www.mathsisfun.com/games/towerofhanoi.html
 **/
int	hanoi(int n, int start, int end)
{
	int	moves, other;

	if (n == 1)
	{
		put_move(start, end);
		return (1);
	}
	other = 6 - (start + end);
	moves = hanoi(n - 1, start, other);
	put_move(start, end);
	moves += 1 + hanoi(n - 1, other, end);
	return (moves);
}

int	main(void)
{
	int	moves;

	moves = hanoi(8, 1, 3);
	printf("\nMoves: %d\n", moves);
}
