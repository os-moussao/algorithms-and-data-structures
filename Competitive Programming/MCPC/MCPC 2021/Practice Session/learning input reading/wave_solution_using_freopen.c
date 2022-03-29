#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <math.h>
#include <limits.h>

int	solve(char *str)
{
	int	i = 0;
	int	count = 0;
	int	max = INT_MIN;

	while (str[i])
	{
		count++;
		if (str[i] == str[i + 1] || !str[i + 1])
		{
			if (count >= max)
			{
				max = count;
			}
			count = 0;
		}
		i++;
	}
	return (max);
}

int	main(void)
{
	FILE *fp = freopen("wave.in", "r", stdin);
	int		T = 0;
	scanf("%d", &T);

	while (T--)
	{
		char	str[1000002] = {0};

		scanf(" %[^\n]", str);
		printf("%d\n", solve(str));
	}
	fclose(fp);
}
