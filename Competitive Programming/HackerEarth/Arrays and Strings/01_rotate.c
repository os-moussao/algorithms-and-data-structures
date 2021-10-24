#include <stdio.h>

int	main(void)
{
	int	T;
	scanf("%d", &T);

	while (T--)
	{
		int n, k;

		scanf("%d%d", &n, &k);
		k = k % n;
		int	arr[n];
		for (int i = 0; i < n; i++)
			scanf("%d", &arr[(i + k>=n)?i + k - n: i + k]);
		for (int i = 0; i < n; i++)
			printf("%d ", arr[i]);
		printf("\n");
	}
}
