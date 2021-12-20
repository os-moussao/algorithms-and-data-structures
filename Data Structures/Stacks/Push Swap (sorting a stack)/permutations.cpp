
#include <stdio.h>
#include <stdbool.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>

using namespace std;

void	put_perm(int stack[], int len)
{
	for (int i = 0; i < len; i++)
		cout << stack[i] << ' ';
	cout << '\n';
}

void	backtrack(int stack[], int valid[], int index, int n, int k, int *total)
{
	if (index == k)
	{
		put_perm(stack, k);
		(*total)++;
		return ;
	}

	for (int choice = 1; choice <= n; choice++)
	{
		if (valid[choice])
		{
			stack[index] = choice;
			valid[choice] = 0;
			backtrack(stack, valid, index + 1, n, k, total);
			valid[choice] = 1;
		}
	}
}

int	permutations(int n, int k)
{
	int	total;
	int	stack[k];
	int	valid[n + 1];

	if (k <= 0 || k > n)
		return (0);
	for (int i = 1; i <= n; i++)
		valid[i] = 1;
	total = 0;
	backtrack(stack, valid, 0, n, k, &total);
	return (total);
}

int	main(void)
{
	int n;
	cin >> n;
	FILE *out = freopen("permutations", "w", stdout);
	permutations(n, n);
	fclose(out);
}
