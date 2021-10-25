#include <stdio.h>

// write-up: https://www.hackerearth.com/practice/codemonk/

int	main(void)
{
	int	T;
	scanf("%d", &T);

	while (T--)
	{
		int	n, ans = 0;
		scanf("%d", &n);

		int	arr[n][n];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				scanf("%d", &arr[i][j]);

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				for (int a = i; a < n; a++)
					for (int b = j; b < n; b++)
						ans += arr[i][j] > arr[a][b];

		printf("%d\n", ans);
	}
}
