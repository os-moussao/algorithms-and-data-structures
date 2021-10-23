#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>

void	shift(int *arr, int l, int r, int d)
{
	int	tmp;

	for (int i = l; i < l + d; i++)
	{
		tmp = arr[l];
		for (int j = l; j < r; j++)
			arr[j] = arr[j + 1];
		arr[r] = tmp;
	}
}

void	disp(int *arr, int n)
{
	for (int i = 0; i < n; i++)
		printf("%d	", arr[i]);
	printf("\n");
}

int	main(void)
{
	int	T;

	scanf("%d", &T);
	while (T-- > 0)
	{
		int	n;
		scanf("%d", &n);

		int	arr[n];
		for (int i = 0; i < n; i++)
			scanf("%d", &arr[i]);
		
		int	ans[n][3];
		int	cnt = 0;
		for (int i = 0; i < n; i++)
		{
			int min = i;

			for (int j = i + 1; j < n; j++)
			{
				if (arr[j] < arr[min])
					min = j;
			}
			if (min - i)
			{
				shift(arr, i, min, min - i);
				ans[cnt][0] = i + 1;
				ans[cnt][1] = min + 1;
				ans[cnt++][2] = min - i;
			}
		}

		printf("%d\n", cnt);
		for (int i = 0; i < cnt; i++)
			printf("%d %d %d\n", ans[i][0], ans[i][1], ans[i][2]);
	}
}
