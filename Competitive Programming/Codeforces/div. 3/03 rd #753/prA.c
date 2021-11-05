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

	while (T--)
	{
		char	kb[27] = {0};
		char	str[60] = {0};
		int		hash[26] = {0};

		scanf(" %[^\n]", kb);
		scanf(" %[^\n]", str);

		for (int i = 0; i < 26; i++)
			hash[kb[i] - 'a'] = i;

		int res = 0;
		for (int i = 0; str[i + 1]; i++)
			res += abs(hash[str[i] - 'a'] - hash[str[i + 1] - 'a']);

		printf("%d\n", res);
	}
}
