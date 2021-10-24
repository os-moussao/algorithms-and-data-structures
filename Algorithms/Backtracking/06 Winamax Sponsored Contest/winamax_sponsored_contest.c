/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   winamax_sponsored_contest.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussao@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 00:41:26 by os-moussao        #+#    #+#             */
/*   Updated: 2021/10/14 02:05:28 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

#define UP '^'
#define DOWN 'v'
#define LEFT '<'
#define RIGHT '>'
#define EMPTHY '.'

#define WATER 'X'
#define HOLE 'H'
#define USED_HOLE '*'
#define USED_BALL '0'

typedef struct	s_pos
{
	int i;
	int	j;
}				t_pos;

typedef struct	s_direction
{
	t_pos	pos;
	char	direction;
}				t_direction;

unsigned int	g_solution_count = 1;

void	copy_ans(char **ans, char **sol, int rows, int cols);
void	put_map(char **map, int rows);
bool	next_ball(char **map, int rows, int cols, t_pos *ball, t_pos *pos);
bool	is_valid_direction(char **map, char **sol, t_pos pos, t_pos adj, int rows, int cols);

void	solve_puzzle(char **map, char **sol, char **ans, int cost, int *min_cost, int rows, int cols, t_pos ball, t_pos prev, t_pos pos)
{
	int	pi = pos.i;
	int	pj = pos.j;
	int	bi = ball.i;
	int	bj = ball.j;

	if (map[pi][pj] == HOLE)
	{
		char	shots = map[bi][bj];
		map[pi][pj] = USED_HOLE;
		map[bi][bj] = USED_BALL;
		if (next_ball(map, rows, cols, &ball, &pos))
			solve_puzzle(map, sol, ans, cost, min_cost, rows, cols, ball, ball, pos);
		else
		{
			printf("\nSolution #%d - Shots taken: %d\n", g_solution_count++, cost);
			put_map(sol, rows);
			if (cost < *min_cost)
			{
				(*min_cost) = cost;
				copy_ans(ans, sol, rows, cols);
			}
		}
		map[pi][pj] = HOLE;
		map[bi][bj] = shots;
		return ;
	}

	t_direction	move[4] =
	{
		{{pi + 1, pj}, DOWN},
		{{pi - 1, pj}, UP},
		{{pi, pj + 1}, RIGHT},
		{{pi, pj - 1}, LEFT}
	};

	for (int i = 0; i < 4; i++)
	{
		if (is_valid_direction(map, sol, pos, move[i].pos, rows, cols))
		{
			char	direction = move[i].direction;
			t_pos	next = move[i].pos;
			bool	changed;
			
			changed = (sol[prev.i][prev.j] != direction);
			if (changed)
			{
				if (map[bi][bj] == '0')
					continue ;
				else
					map[bi][bj]--,
					cost++;
			}
			sol[pi][pj] = direction;
			if (map[next.i][next.j] == WATER)
			{
				next = (t_pos){2 * next.i - pi, 2 * next.j - pj};
				sol[move[i].pos.i][move[i].pos.j] = direction;
				solve_puzzle(map, sol, ans, cost, min_cost, rows, cols, ball, pos, next);
				
				// Backtrack
				sol[move[i].pos.i][move[i].pos.j] = EMPTHY;
			}
			else
				solve_puzzle(map, sol, ans, cost, min_cost, rows, cols, ball, pos, next);
			
			// Backtrack
			sol[pi][pj] = EMPTHY;
			if (changed)
				map[bi][bj]++, cost--;
		}
	}
}

int	main(void)
{
    int		width;
    int		height;
	char	**map, **sol, **ans;

    scanf("%d%d", &width, &height);
    
	map = malloc(height * sizeof(char *));
	sol = malloc(height * sizeof(char *));
	ans = malloc(height * sizeof(char *));
	for (int i = 0; i < height; i++)
	{
		map[i] = calloc(width + 1, 1);
		sol[i] = calloc(width + 1, 1);
		ans[i] = calloc(width + 1, 1);
        scanf("%s", map[i]);
		for (int j = 0; j < width; j++)
			sol[i][j] = ans[i][j] = '.';
    }
	t_pos	ball;
	int		min_cost = INT_MAX;
	next_ball(map, height, width, &ball, &ball);
	solve_puzzle(map, sol, ans, 0, &min_cost, height, width, ball, ball, ball);
	/*
	printf("\nResult:\n");
	put_map(ans, height);
	*/
    return (0);
}

bool	is_valid_direction(char **map, char **sol, t_pos pos, t_pos adj, int rows, int cols)
{
	int	ai = adj.i;
	int	aj = adj.j;

	// out of bounds test
	if (ai < 0 || ai >= rows || aj < 0 || aj >= cols)
		return (false);

	// path crossed or used hole or another ball test
	if (sol[ai][aj] != EMPTHY || map[ai][aj] == USED_HOLE || (map[ai][aj] >= '0' && map[ai][aj] <= '9'))
		return (false);

	// water test
	if (map[ai][aj] == WATER)
	{
		int		pi = pos.i;
		int		pj = pos.j;
		t_pos	next = (t_pos){2 * ai - pi, 2 * aj - pj};

		/*	
		if (next.i < 0 || next.i >= rows || next.j < 0 || next.j >= cols)
			return (false);
		*/
		return is_valid_direction(map, sol, adj, next, rows, cols);
	}

	// if all test are passed, then it's a valid adjacent
	
	return (true);
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

void	put_map(char **map, int rows)
{
	for (int i = 0; i < rows; i++)
		printf("%s\n", map[i]);
}

void	copy_ans(char **ans, char **sol, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			ans[i][j] = sol[i][j];
}

