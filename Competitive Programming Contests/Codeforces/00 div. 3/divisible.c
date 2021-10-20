#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>

int	solve(char *str)
{
	bool	nbr1 = false; // 5
	bool	nbr2 = false; // 0
	int	i = strlen(str) - 1;
	int	count = 0;

	while (i)
	{
		if (!nbr1 && str[i] == '5')
			nbr1 = true, i--;
		else if (!nbr2 && str[i] == '0')
			nbr2 = true, i--;
		else if (nbr1 && (str[i] == '2' || str[i] == '7'))
			return count;
		else if (nbr2 && (str[i] == '0' || str[i] == '5'))
			return count;
		else
			i--, count++;
	}
	return count;
}

int	main(void)
{
	int	T;

	scanf("%d", &T);
	while (T-- > 0)
	{
		char	str[20];

		scanf(" %[^\n]%*c", str);
		printf("%d\n", solve(str));
	}
}
