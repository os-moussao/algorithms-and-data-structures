#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <math.h>
#include <limits.h>

int	main(void)
{
	char	buff[1000];
	int		fd = open("eat.in", O_RDONLY);
	read(fd, buff, 1000);
	int		T = 0;

	// read number of tests from the 1st line
	int i = 0;
	while (buff[i] && buff[i] != '\n')
		T =T * 10 + (buff[i++] - '0');

	while (T-- > 0)
	{
		// read remaining lines from the file
	}
}

