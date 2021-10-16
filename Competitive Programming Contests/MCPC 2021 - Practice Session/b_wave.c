#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
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
	char	buff[1000] = {0};
	int		fd = open("wave.in", O_RDONLY);
	read(fd, buff, 1000);
	int		T = 0;
	int		i = 0;

	while (buff[i] && buff[i] != '\n')
		T =T * 10 + (buff[i++] - '0');
	while (T--)
	{
		char	str[1000002] = {0};
		int		j = 0;

		i++;
		while (buff[i] && buff[i] !='\n')
			str[j++] = buff[i++];
		printf("%d\n", solve(str));
	}
}
