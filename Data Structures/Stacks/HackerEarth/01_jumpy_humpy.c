#include <stdio.h>

/**
 * not solved yet
 **/

int	main(void)
{
	int	n;
	scanf("%d", &n);
	
	int	arr[n];
	for (int i  = 0; i < n; i++)
		scanf("%d", &arr[i]);

	int	max = -1;

	for (int i = 0; i < n; i++)
	{
		int	j = i;
		int	k = i + 1;
		int	sta = arr[i];

		while (k < n && arr[k] > arr[j++])
			sta ^= arr[k++];

		printf("stamina from %d to %d = %d\n", arr[i], arr[k - 1], sta);
		if (max < sta)
			max = sta;
	}

	printf("%d\n", max);
}
