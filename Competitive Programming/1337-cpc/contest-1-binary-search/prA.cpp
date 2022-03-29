#include <iostream>
#include <cmath>
using namespace std;

#define int long long

struct pt{
	int x;
	int v;
};


int32_t	main(void)
{
	char	str[20] = {0};
	char	c;
	cin >> str >> c;

	int i = 0, yes = 1;
	while (str[i])
		if (str[i++] == c)
			yes = 0;
	if (yes)
		cout << "YES\n";
	else
		cout << "NO\n";
}
