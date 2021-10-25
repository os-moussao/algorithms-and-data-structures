#include <stdio.h>
#include <string.h>

void	shift(char *arr, int n)
{
	char	tmp = arr[0];
	for (int i = 0; i < n - 1; i++)
		arr[i] = arr[i + 1];
	arr[n - 1] = tmp;
}

int	main(void)
{
	int	T;
	scanf("%d", &T);

	while (T--)
	{
		long long unsigned int	n, k;
		scanf("%llu%llu", &n, &k);

		char	arr[n + 1];
		scanf(" %[^\n]", arr);

		char	b[n + 1];
		b[0] = 0;
		long long unsigned int	d;
		long long unsigned int	p = -1;
		for (int i = 0; i < n; i++)
		{
			int	cmp = strncmp(b, arr, n);
			if (cmp < 0)
			{
				strncpy(b, arr, n);
				d = i;
			}
			else if (cmp == 0)
			{
				p = i - d;
				break;
			}
			shift(arr, n);
		}
		long long unsigned int	ans = (p == -1)? d + (k - 1) * n:d + (k - 1) * p;
		printf("%llu\n", ans);
	}
}

