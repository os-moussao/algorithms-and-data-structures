#include <iostream>
#include <cmath>
using namespace std;

#define int long long

int	power(int b, int e)
{
	if (e == 0)
		return (1);
	if (e % 2 == 0)
		return (power(b*b, e / 2));
	else
		return (b * power(b*b, (e - 1) / 2));
}

int32_t	main(void)
{
	int	n;
	cin >> n;

	cout << power(3, n) << "\n";
}
