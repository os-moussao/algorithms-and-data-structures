/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   winamax_sponsored_contest.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussao@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 00:41:26 by os-moussao        #+#    #+#             */
/*   Updated: 2021/10/13 22:07:47 by os-moussao       ###   ########.fr       */
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

/*
char	ans[5][5] = 
{
	"v....",
	"v...<",
	"v^..^",
	"v^.^^",
	">>>^."
};

bool	equal(char **sol, char ans[][5])
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (sol[i][j] != ans[i][j])
				return (false);
		}
	}
	return (true);
}
*/

void	put_map(char **map, int rows, int cols);
bool	next_ball(char **map, int rows, int cols, t_pos *ball, t_pos *pos);

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

bool	solve_puzzle(char **map, char **sol, int rows, int cols, t_pos ball, t_pos prev, t_pos pos)
{
	int	pi = pos.i;
	int	pj = pos.j;
	int	bi = ball.i;
	int	bj = ball.j;
	
	if (map[bi][bj] == '0' || map[pi][pj] == HOLE)
	{
		if (map[pi][pj] != HOLE)
			return (false);

		char	left = map[bi][bj];
		map[pi][pj] = USED_HOLE;
		map[bi][bj] = USED_BALL;
		if (next_ball(map, rows, cols, &ball, &pos))
		{
			if (solve_puzzle(map, sol, rows, cols, ball, ball, pos))
				return (true);
			map[pi][pj] = HOLE;
			map[bi][bj] = left;
			return (false);
		}
		else
			return (true);
	}

	t_direction	move[4] =
	{
		{{pi, pj - 1}, LEFT},
		{{pi + 1, pj}, DOWN},
		{{pi, pj + 1}, RIGHT},
		{{pi - 1, pj}, UP}
	};

	for (int i = 0; i < 4; i++)
	{
		if (is_valid_direction(map, sol, pos, move[i].pos, rows, cols))
		{
			char	direction = move[i].direction;
			t_pos	next = move[i].pos;
			bool	changed;
			
			changed = (sol[prev.i][prev.j] != direction);
			sol[pi][pj] = direction;
			if (changed)
				map[bi][bj]--;
			if (map[next.i][next.j] == WATER)
			{
				next = (t_pos){2 * next.i - pi, 2 * next.j - pj};
				sol[move[i].pos.i][move[i].pos.j] = direction;
				if (solve_puzzle(map, sol, rows, cols, ball, pos, next))
					return (true);
				sol[move[i].pos.i][move[i].pos.j] = EMPTHY;
			}
			else
			{
				if (solve_puzzle(map, sol, rows, cols, ball, pos, next))
					return (true);
			}
			sol[pi][pj] = EMPTHY;
			if (changed)
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
	solve_puzzle(map, sol, height, width, ball, ball, ball);
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
