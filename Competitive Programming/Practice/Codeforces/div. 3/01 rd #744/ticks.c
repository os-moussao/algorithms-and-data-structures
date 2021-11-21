#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>

int	main(void)
{
	int	T;

	scanf("%d", &T);
	while (T-- > 0)
	{
		int	n, m, k;
		scanf("%d%d%d", &n, &m, &k);

		char	bd[n][m];
		int		status[n][m];
		for (int i = 0; i < n; i++)
		{
			scanf(" %[^\n]%*c", bd[i]);
			for (int j = 0; j < m; j++)
				status[i][j] = (bd[i][j] == '.')? k + 1 : 0;
		}

		for (int i = n - 1; i >= 0; i--)
		{
			for (int j = 0; j < m; j++)
			{
				if (bd[i][j] == '*')
				{
					for (int d = 1; d <= i; d++)
					{
						if (bd[i - d][j - d] == '*' && bd[i - d][j + d] == '*' && (j + d < m && j - d >= 0))
						{
							status[i][j] = status[i][j] < d? d: status[i][j];
							for (int a = 1; a <= d; a++)
							{
								status[i - a][j - a] = status[i - a][j - a] < d? d: status[i - a][j - a];
								status[i - a][j + a] = status[i - a][j + a] < d? d: status[i - a][j + a];
							}
						}
						else
							break ;
					}
				}
			}
		}

		bool	valid = true;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (status[i][j] < k)
					valid = false;
			}
		}
		printf("%s\n", valid? "YES": "NO");
	}
}
