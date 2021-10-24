#include <stdio.h>

void	res_push(char *res, int r)
{
	for (int i = 51; i >= 1; i--)
		res[i] = res[i - 1];
	res[0] = (r % 10) + '0';
}

int	main(void)
{
	// addition will be done column by column
	// because the numbers are too big for an int value (or even an unsigned long long int)
	
	// 100 * 50-digit numbers
	// so we need an 2D array of 100 * 50
	char	nums[100][50];

	// we need an array to store the result
	// technically a size of 52 is enough
	// because a carry will never be more than 2 digits (my intuition says that)
	// but taking more than enough space will never hurt :)
	char	res[100] = {0};

	// a variable to store the carry
	int		carry = 0;

	// the numbers are so big to split by hand
	// so better to put them in a file and read from the file
	FILE	*fp = freopen("13_large_sum.in", "r", stdin);
	for (int i = 0; i < 100; i++)
		scanf(" %[^\n]%*c", nums[i]);

	// add numbers of each column and update the result
	for (int j = 49; j >= 0; j--)
	{
		// add carry
		int sum = carry;

		// count sum
		for (int i = 0; i < 100; i++)
			sum += nums[i][j] - '0';

		// push the first digit to result
		res_push(res, sum % 10);

		// update the carry
		carry = sum / 10;
	}

	// finally add the carry
	while (carry)
		res_push(res, carry % 10), carry /= 10;

	// print result
	printf("%s\n", res);
	fclose(fp);
}
