/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chill_zone_fun.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussao@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 14:20:57 by os-moussao        #+#    #+#             */
/*   Updated: 2021/10/11 17:53:52 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
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
	pos	adj[4] =
	{
		{S.i - 1, S.j},
		{S.i + 1, S.j},
		{S.i, S.j + 1},
		{S.i, S.j - 1}
	};

	for (int a = 0; a < 4; a++)
	{
		if (is_valid_adj(map, adj[a], rows, cols))
		{
			int		sr = S.i;
			int		sc = S.j;
			char	ch = map[sr][sc];

			if (ch == '.')
			{
				map[sr][sc] = '*';
				min_cost_path(map, rows, cols, adj[a], cost + 1, min);
				map[sr][sc] = ch;
			}
			else if (ch == 'K')
			{
				// treat it as a '.'
				map[sr][sc] = '*';
				min_cost_path(map, rows, cols, adj[a], cost + 1, min);
				map[sr][sc] = ch;

				// find another 'K'
				for (int i = 0; i < rows; i++)
				{
					for (int j = 0; j < cols; j++)
					{
						if (map[i][j] == 'K' && i != sr && j != sc)
						{
							map[sr][sc] = '*';
							pos	adj = {i, j};
							min_cost_path(map, rows, cols, adj, cost, min);
							map[sr][sc] = ch;
						}
					}
				}
			}
			else if (map[sr][sc] == 'T')
			{
				if (cost < *min)
					*min = cost;
				return ;
			}
		}
	}
}

int	main(void)
{
	int	T;

	scanf("%d", &T);

	int	solution[T];
	for (int i = 0; i < T; i++)
	{
		int		rows, cols;
		int		min_cost = INT_MAX;
		char	**map;
		pos		S;

		scanf("%d %d", &rows, &cols);
		map = malloc(rows * sizeof(rows));
		for (int j = 0; j < rows; j++)
		{
			map[j] = malloc(cols);
			scanf(" %[^\n]", map[j]);
		}
		S = find_start(map, rows, cols);
		min_cost_path(map, rows, cols, S, 0, &min_cost);
		solution[i] = min_cost;
	}

	for (int i = 0; i < T; i++)
		printf("%d\n", solution[i]);

	return (0);
}
