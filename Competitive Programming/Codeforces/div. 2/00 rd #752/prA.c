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
		int	n;
		scanf("%d", &n);

		int	arr[n];
		for (int i = 0; i < n; i++)
			scanf("%d", &arr[i]);

		int	res = 0;

		for (int i = 0; i < n; i++)
		{
			if (arr[i] > i + 1)
			{
				int	diff = 0;
				res += (diff = arr[i] - (i + 1));
				for (int j = i + 1; j < n; j++)
					arr[j] -= diff;
			}
		}

		printf("%d\n", res);
	}
}
