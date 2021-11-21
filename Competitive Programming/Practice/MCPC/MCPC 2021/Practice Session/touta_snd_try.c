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
		char	strA[25];
		char	strB[25];
		long long int	a, b;
		int	j = 0, i = 0;
		fgets(line, LINE_SIZE, fd);

		while (line[i] != ' ')
			strA[j++] = line[i++];

		j = 0;
		while (line[i] != '\n')
			strB[j++] = line[i++];

		char	*endptr;
		a = strtol(strA, &endptr, 10);
		b = strtol(strB, &endptr, 10);
		
		// printf("a = %lld b = %lld	a+b = %lld a*b =%lld\n", a + b, a * b);
		printf("Plate %d\n", a + b> a*b? 1: 2);
	}
}
