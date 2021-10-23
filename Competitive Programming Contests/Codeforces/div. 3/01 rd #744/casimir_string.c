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
		char	str[51];

		scanf(" %[^\n]%*c", str);
		int	l = strlen(str);
		int cnt = 0;
		for (int i = 0; i < l; i++)
			cnt += (str[i] == 'A' || str[i] == 'C') - (str[i] == 'B');
		printf("%s\n", cnt?"NO":"YES");
	}
}
