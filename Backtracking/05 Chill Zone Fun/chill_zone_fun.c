/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chill_zone_fun.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussao@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 14:20:57 by os-moussao        #+#    #+#             */
/*   Updated: 2021/10/11 21:45:50 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct	s_pos
{
	int	i;
	int	j;
}				pos;

bool	is_valid_adj(char **map, pos adj, int rows, int cols)
{
	if (adj.i < 0 || adj.i >= rows || adj.j < 0 || adj.j >= cols)
		return (false);
	if (map[adj.i][adj.j] == '*')
		return (false);
	return (true);
}

pos	find_start(char **map, int rows, int cols)
{
	pos	S = {0, 0};

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (map[i][j] == 'S')
			{
				S = (pos){.i = i, .j = j};
				return (S);
			}
		}
	}
	return  (S);
}

void	min_cost_path(char **map, int rows, int cols, pos S, int cost, int *min)
{
	int	r = S.i;
	int	c = S.j;

	if (map[r][c] == 'T')
	{
		if (cost < *min || *min == -1)
			*min = cost;
		return ;
	}

	pos	adj[4] =
	{
		{r - 1, c},
		{r + 1, c},
		{r, c + 1},
		{r, c - 1}
	};

	for (int i = 0; i < 4; i++)
	{
		if (is_valid_adj(map, adj[i], rows, cols))
		{
			char	value = map[r][c];

			map[r][c] = '*';
			min_cost_path(map, rows, cols, adj[i], cost + 1, min);
			map[r][c] = value;
		}
	}
	
	if (map[r][c] == 'K')
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				if (map[i][j] == 'K' && !(i = r && j == c))
				{
					map[r][c] = '*';
					pos	adj = {i, j};
					min_cost_path(map, rows, cols, adj, cost, min);
					map[r][c] = 'K';
				}
			}
		}
	}
}

int	main(void)
{
	int		T;

	scanf("%d", &T);

	int	solution[T];
	for (int i = 0; i < T; i++)
	{
		int		rows, cols;
		int		min_cost = -1;
		char	**map;
		pos		S;

		scanf("%d %d", &rows, &cols);
		map = malloc(rows * sizeof(char *));
		for (int j = 0; j < rows; j++)
		{
			map[j] = malloc(cols);
			scanf(" %[^\n]%*c", map[j]);
		}
		
		S = find_start(map, rows, cols);
		min_cost_path(map, rows, cols, S, 0, &min_cost);
		solution[i] = min_cost;
	}

	for (int i = 0; i < T; i++)
		printf("%d\n", solution[i]);

	return (0);
}
