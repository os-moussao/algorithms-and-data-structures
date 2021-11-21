#include <iostream>
#include <cmath>
using namespace std;

#define int long long

bool	cmp(string s1, string s2)
{
	return (s1 < s2);
}

int32_t	main(void)
{
	int n, m;
	cin >> n >> m;

	string	ens[n];
	string	ems[m];
	for (int i = 0; i < n; i++)
		cin >> ens[i];
	for (int i = 0; i < m; i++)
		cin >> ems[i];

	sort(ens, ens + n, cmp);

	for (int i = 0; i< m; i++)
	{
		bool	in = false;
		int l = 0, h = n - 1, mid;
		while (h >= l)
		{
			mid = l + (h - l) / 2;
			if (ems[i] == ens[mid])
			{
				in = true;
				break ;
			}
			if (ems[i] < ens[mid])
				h = mid - 1;
			else
				l = mid + 1;
		}
		if (in)
			cout << "IN\n";
		else
			cout << "OUT\n";
	}
}
