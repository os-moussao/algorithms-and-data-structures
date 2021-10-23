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
		int	n, m, k, ans = 1;
		scanf("%d%d%d", &n, &m, &k);

		char	f[n][m];
		char	x[n][m];
		for (int i = 0; i < n; i++)
		{
			scanf(" %[^\n]%*c", f[i]);
			for (int j = 0; j < m; j++)
				x[i][j] = 0;
		}

		for (int i = n - 1; i >= 0; i--)
		{
			for (int j = 0; j < m; j++)
			{
				if (f[i][j] == '*')
				{
					int size = 0;
					for (int d = 1; d < i; d++)
					{
						if (f[i - d][j - d] == '*' && f[i - d][j + d] == '*')
						{
							size++;
							x[i - d][j - d] = x[i - d][j + d] = 1;
						}
						else
							break ;
					}
					if (size < k || (size == 0 && !x[i][j]))
						ans = 0;
				}
			}
		}
		printf("%s\n", ans?"YES":"NO");
	}
}
