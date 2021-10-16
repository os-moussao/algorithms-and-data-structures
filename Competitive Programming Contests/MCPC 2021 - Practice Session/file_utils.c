#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <math.h>
#include <limits.h>

#define LINE_SIZE 150

int	main(void)
{
	FILE	*fd = fopen("eat.in", "r");
	char	line[LINE_SIZE];
	int		T = 0;

	fgets(line, LINE_SIZE, fd);
	T = atoi(line);
	while (!feof(fd) && T-- > 0)
	{
		fgets(line, LINE_SIZE, fd);
		printf("%s", line);
	}
}
