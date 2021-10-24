#include <stdio.h>

int	main(void)
{
	int	T;
	scanf("%d", &T);

	while (T--)
	{
		int n, k;

		scanf("%d%d", &n, &k);
		int	arr[n];
		for (int i = 0; i < n; i++)
			scanf("%d", &arr[(i + k) % n]);
		for (int i = 0; i < n; i++)
			printf("%d ", arr[i]);
		printf("\n");
	}
}
