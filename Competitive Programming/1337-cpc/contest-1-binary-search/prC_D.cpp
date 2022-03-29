#include <iostream>
#include <cmath>
using namespace std;

#define int long long

int	power(int b, int e)
{
	b = b % ((int)(1e9 + 7));
	if (e == 0)
		return (1);
	if (e % 2 == 0)
		return ((power(b*b, e / 2)) % (int) (1e9 + 7));
	else
		return ((b * (power(b*b, (e - 1) / 2) % (int) (1e9 + 7)) ) % (int) (1e9 + 7));
}

int32_t	main(void)
{
	int	n;
	cin >> n;

		cout <<  power(3, n) << "\n";
}
