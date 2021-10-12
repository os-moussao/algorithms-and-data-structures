/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   winmax_codingame_contest.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussao@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 00:41:26 by os-moussao        #+#    #+#             */
/*   Updated: 2021/10/12 13:47:12 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define UP '^'
#define DOWN 'v'
#define LEFT '<'
#define RIGHT '>'
#define EMPTHY '.'

#define WATER 'X'
#define HOLE 'H'

typedef struct	s_pos
{
	int i;
	int	j;
}				t_pos;

bool	next_ball(char **map, int rows, int cols, t_pos *ball, t_pos pos)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (map[i][j] >= 1 && map[i][j] <= 9)
			{
				ball->i = pos->i = i;
				ball->j = pos->j = j;
				return (true);
			}
		}
	}
	return (false);
}

bool	is_valid_direction(char **map, t_pos pos, t_pos adj, int rows, int cols)
{
	int	ai = adj.i;
	int	aj = adj.j;

	// out of bounds test
	if (ai < 0 || ai >= rows || aj < 0 || aj >= cols)
		return (false);

	// water test
	if (map[ai][aj] = WATER)
	{
		int	pi = pos.i;
		int	pj = pos.j;
		int	next_i = 2 * ai - pi;
		int	next_j = 2 * aj - pj;

		if (next_i < 0 || next_i >= rows || next_j < 0 || next_j >= cols)
			return (false)
	}

	return (true);
}

bool	solve_puzzle(char **map, char **sol, int rows, int cols, t_pos ball, t_pos pos)
{
	int	pi = pos.i;
	int	pj = pos.j;
	int	bi = ball.i;
	int	bj = ball.j;
	int	count = map[bj][bi] - '0';

	if (map[bj][bi] == '0' || map[pi][pj] == HOLE)
	{
		if (map[pi][pj] != HOLE)
			return (false);
		if (next_ball(map, rows, cols, &ball, &pos))
			return solve_puzzle(map, sol, rows, cols, ball, pos);
		else
			return (true);
	}

	t_pos	adj[4] =
	{
		{r - 1, c},	// UP
		{r + 1, c},	// DOWN
		{r, c + 1},	// RIGHT
		{r, c - 1}	// LEFT
	};

	for (int i = 0; i < 4; i++)
	{
		if (is_valid_direction(map, pos, adj[i], rows, cols))
		{
			char	direction = (i == 0)? UP: (i == 1)? DOWN: (i == 2)? RIGHT: LEFT;
			
			map[bj][bi]--;
			sol[pi][pj] = direction;
			if (solve_puzzle(map, sol, rows, cols, ball, adj[i]))
				return (true);
			map[bj][bi]++;
			sol[pi][pj] = EMPTHY;
		}
	}
}

int	main(void)
{
    int		width;
    int		height;
	char	**map, **sol;

    scanf("%d%d", &width, &height);
    
	map = malloc(height * sizeof(char *));
	sol = malloc(height * sizeof(char *));
	for (int i = 0; i < height; i++)
	{
		map[i] = calloc(width + 1, 1);
		sol[i] = calloc(width + 1, 1);
        scanf("%s", map[i]);
		for (int j = 0; j < width; j++)
			sol[i][j] = '.';
    }
    return 0;
}
