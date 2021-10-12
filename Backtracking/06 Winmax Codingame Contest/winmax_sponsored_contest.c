/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   winmax_sponsored_contest.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussao@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 00:41:26 by os-moussao        #+#    #+#             */
/*   Updated: 2021/10/12 17:44:58 by os-moussao       ###   ########.fr       */
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
#define USED_HOLE '*'

typedef struct	s_pos
{
	int i;
	int	j;
}				t_pos;

void	put_map(char **map, int rows, int cols);
bool	next_ball(char **map, int rows, int cols, t_pos *ball, t_pos *pos);

bool	is_valid_direction(char **map, char **sol, t_pos pos, t_pos adj, int rows, int cols)
{
	int	ai = adj.i;
	int	aj = adj.j;

	// out of bounds test
	if (ai < 0 || ai >= rows || aj < 0 || aj >= cols)
		return (false);

	// path crossed or used hole test
	if (sol[ai][aj] != EMPTHY || map[ai][aj] == USED_HOLE)
		return (false);

	// water test
	if (map[ai][aj] == WATER)
	{
		int	pi = pos.i;
		int	pj = pos.j;
		int	next_i = 2 * ai - pi;
		int	next_j = 2 * aj - pj;

		if (next_i < 0 || next_i >= rows || next_j < 0 || next_j >= cols)
			return (false);
	}

	// if all test are passed, then it's a valid adjacent
	return (true);
}

bool	solve_puzzle(char **map, char **sol, int rows, int cols, t_pos ball, t_pos pos)
{
	int	pi = pos.i;
	int	pj = pos.j;
	int	bi = ball.i;
	int	bj = ball.j;
	
	if (map[bi][bj] == '0' || map[pi][pj] == HOLE)
	{
		if (map[pi][pj] != HOLE)
			return (false);
		map[pi][pj] = USED_HOLE;
		if (next_ball(map, rows, cols, &ball, &pos))
			return solve_puzzle(map, sol, rows, cols, ball, pos);
		else
			return (true);
	}

	t_pos	adj[4] =
	{
		{pi - 1, pj},	// UP
		{pi + 1, pj},	// DOWN
		{pi, pj + 1},	// RIGHT
		{pi, pj - 1}	// LEFT
	};

	for (int i = 0; i < 4; i++)
	{
		if (is_valid_direction(map, sol, pos, adj[i], rows, cols))
		{
			char	direction = (i == 0)? UP: (i == 1)? DOWN: (i == 2)? RIGHT: LEFT;
			t_pos	next = adj[i];
			
			sol[pi][pj] = direction;
			map[bi][bj]--;
			if (map[next.i][next.j] == WATER)
			{
				next = (t_pos){2 * next.i - pi, 2 * next.j - pj};
				sol[adj[i].i][adj[i].j] = direction;
				if (solve_puzzle(map, sol, rows, cols, ball, next))
					return (true);
				sol[adj[i].i][adj[i].j] = EMPTHY;
			}
			else
			{
				if (solve_puzzle(map, sol, rows, cols, ball, next))
					return (true);
			}
			sol[pi][pj] = EMPTHY;
			map[bi][bj]++;
		}
	}

	return (false);
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
	t_pos	ball;
	next_ball(map, height, width, &ball, &ball);
	solve_puzzle(map, sol, height, width, ball, ball);
	printf("Result:\n");
	put_map(sol, height, width);
    return (0);
}

bool	next_ball(char **map, int rows, int cols, t_pos *ball, t_pos *pos)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (map[i][j] >= '1' && map[i][j] <= '9')
			{
				ball->i = pos->i = i;
				ball->j = pos->j = j;
				return (true);
			}
		}
	}
	return (false);
}

void	put_map(char **map, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			printf("%c", map[i][j]);
		printf("\n");
	}
}
