#include <stdio.h>

void	res_push(char *res, int r)
{
	for (int i = 51; i >= 1; i--)
		res[i] = res[i - 1];
	res[0] = (r % 10) + '0';
}

int	main(void)
{
	char	nums[100][50];
	char	res[52] = {0};
	int		carry[2] = {0};

	for (int i = 0; i < 100; i++)
		scanf(" %[^\n]%*c", nums[i]);

	for (int j = 49; j >= 0; j--)
	{
		int sum = 0;
		for (int i = 0; i < 100; i++)
			sum += nums[i][j] - '0';
		sum += carry[0] + 10 * carry[1];
		res_push(res, sum % 10);
		carry[0] = (sum / 10) % 10;
		carry[1] = (sum / 100) % 10;
	}
	printf("%s\n", res);
}
