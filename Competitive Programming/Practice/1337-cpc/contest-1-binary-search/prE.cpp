#include <iostream>
#include <cmath>
using namespace std;

#define int long long

int	ans[4] = {0, 1, 2, 4};

int	solve(int n)
{
	if (n <= 3)
		return (ans[n]);
	for (int i = 4; i <= n; i++)
	{
		int tmp = ans[1] + ans[2] + ans[3];
		for (int j = 0; j < 3; j++)
			ans[j] = ans[j + 1];
		ans[3] = tmp;
	}
	return ans[3];
}

int32_t	main(void)
{
	int n;
	cin >> n;

	cout << solve(n) << "\n";
}
