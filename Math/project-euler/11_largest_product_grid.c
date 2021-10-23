#include <stdio.h>

int	main(void)
{
	int	arr[20][20];
	int	max = -1;
	int	prod;

	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 20; j++)
			scanf("%d", &arr[i][j]);

	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 17; j++)
		{
			prod = arr[i][j] * arr[i][j + 1] * arr[i][j + 2] * arr[i][j + 3];
			if (prod > max)
				max = prod;
		}
	}

	for (int j = 0; j < 20; j++)
	{
		for (int i = 0; i < 17; i++)
		{
			prod = arr[i][j] * arr[i + 1][j] * arr[i + 2][j] * arr[i + 3][j];
			if (prod > max)
				max = prod;
		}
	}

	for (int i = 0; i < 17; i++)
	{
		for (int j = 0; j < 17; j++)
		{
			prod = arr[i][j] * arr[i + 1][j + 1] * arr[i + 2][j + 2] * arr[i + 3][j + 3];
			if (prod > max)
				max = prod;
		}
	}

	for (int i = 0; i < 17; i++)
	{
		for (int j = 3; j < 20; j++)
		{
			prod = arr[i][j] * arr[i + 1][j - 1] * arr[i + 2][j - 2] * arr[i + 3][j - 3];
			if (prod > max)
				max = prod;
		}
	}
	
	printf("%d\n", max);
	/*
	 * it just worked from the first time, no headaches no wrong answer lol */
}
