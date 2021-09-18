/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tower_of_hanoi_special_rule.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussaoui040@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 16:01:01 by os-moussao        #+#    #+#             */
/*   Updated: 2021/09/18 20:37:22 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Special Rule: Plates can only be moved to the adjacent pole
 **/
#include <stdio.h>
#include <stdlib.h>

int	put_move(int from, int to)
{
	printf("%d -> %d\n", from, to);
	return (1);
}

// if distance = 2
// move n - 1 from start to end
// move start -> adj
// move n - 1 from end to start
// move adj -> end
// move n - 1 from start to end
//
// if distance = 1
// move n - 1 from start to other
// move start -> end
// move n - 1 from other to end
int	hanoi(int n, int start, int end)
{
	int	moves = 0;
	int	adj;
	int	other;

	if (n == 0)
		return (0);
	if (abs(start - end) == 2)
	{
		adj = (start == 2)? 4 - end: 2;
		moves += hanoi(n - 1, start, end);
		moves += put_move(start, adj);
		moves += hanoi(n - 1, end, start);
		moves += put_move(adj, end);
		moves += hanoi(n - 1, start, end);
	}
	else
	{
		other = 6 - start - end;
		moves += hanoi(n - 1, start, other);
		moves += put_move(start, end);
		moves += hanoi(n - 1, other, end);
	}
	return (moves);
}

int	main(void)
{
	int	moves;

	moves = hanoi(3, 1, 3);
	printf("\nMoves: %d\n", moves);
}
