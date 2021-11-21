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
		int	a, b;
		char	str[100];

		scanf("%d%d", &a, &b);
		scanf(" %[^\n]%*c", str);
		printf("%d\n", a+b);
	}
}
