#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>

/*
bool	all_vis(char *vis, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for ( int j = 0; j < cols; j++)
		{
			if (!vis[i][j])
				return (false);
		}
	}
	return (true);
}

bool	solve(int *bd, int *vis, int rows, int cols, int i, int j, int min, int k)
{
	if (all_vis(vis, rows, cols))
		return (min >= k);

	
}
*/
int	main(void)
{
	int	T;

	scanf("%d", &T);
	while (T-- > 0)
	{
		int	n, m, k, ans = 1;
		scanf("%d%d%d", &n, &m, &k);

		char	bd[n][m];
		char	vis[n][m];
		for (int i = 0; i < n; i++)
		{
			scanf(" %[^\n]%*c", bd[i]);
			for (int j = 0; j < m; j++)
				vis[i][j] = (bd[i][j] == '.');
		}

		bool	stop = false;
		for (int i = n - 1; i >= 0; i--)
		{
			for (int j = 0; j < m; j++)
			{
				if (bd[i][j] == '*')
				{
					int 	size = 0;
					bool	tick_visited = true;

					if (!vis[i][j])
						tick_visited == false;

					vis[i][j] = 1;

					for (int d = 1; d <= i; d++)
					{
						if (bd[i - d][j - d] == '*' && bd[i - d][j + d] == '*')
						{
							if (!vis[i - d][j - d] || !vis[i - d][j + d])
								tick_visited = false;

							vis[i - d][j - d] = vis[i - d][j + d] = 1;

							size++;
						}
						else
							break ;
					}

					if (size < k && !tick_visited)
					{
						stop = true;
						break ;
					}
				}
				if (stop)
					break ;
			}
		}
		if (!stop)
			printf("YES\n");
	}
}
