#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int	main(void)
{
	char	buff[1000];
	int		fd = open("eat.in", O_RDONLY);
	read(fd, buff, 1000);
	int		T = 0;

	int i = 0;
	while (buff[i] && buff[i] != '\n')
		T =T * 10 + (buff[i++] - '0');
	while (T-- > 0)
	{
		char	strA[25] = {0};
		char	strB[25] = {0};
		char 	*endA, *endB;
		long long	a, b;
		int	j = 0;
		
		
		i++;
		while (buff[i] != ' ')
			strA[j++] = buff[i++];

		i++;
		j = 0;
		while (buff[i] != '\n' && buff[i])
			strB[j++] = buff[i++];
		
		a = strtol(strA, &endA, 10);
		b = strtol(strB, &endB, 10);
		printf("a = %lld b = %lld	a+b = %lld a*b =%lld\n", a + b, a * b);
		printf("Plate %d\n", a + b> a*b? 1: 2);
	}
}
