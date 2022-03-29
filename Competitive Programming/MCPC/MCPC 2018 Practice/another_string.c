#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

int	main(void)
{
	int	T;

	scanf("%d", &T);
	while (T--)
	{
		char	tmp;
		char	str[101];
		
		scanf(" %[^\n]", str);
		if (str[1])
		{
		tmp = str[0];
		str[0] = str[1];
		str[1] = tmp;
		}
		printf("%s\n", str);
	}
}
