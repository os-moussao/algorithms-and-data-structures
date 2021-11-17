// https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/D
#include <iostream>
#include <cmath>
using namespace std;

#define int long long

struct ps
{
	int t, z, y, m;
};
/*
bool	valid2(int t, int z, int y, int bl, int time)
{
	
}*/

bool	valid(ps *arr, int n, int m, int time)
{
	// calc how many ballons can be inflated by each ps 
	// add them
	// compare with m
	// if valid save ps.m
	int total = 0;
	for (int i = 0; i < n; i++)
	{
		int t = arr[i].t;
		int z = arr[i].z;
		int y = arr[i].y;
		int m = arr[i].m = floor(time / ceil((t * z + y) / z));
		/*
		// lets search max balloons can be inflated in time
		int lo = 0, hi = 1e9, mid;
		while (lo + 1 < h)
		{
			mid = l + (h - l) / 2;
			if (valid2(t, z, y, mid, time))
				l = mid;
			else
				h = mid;
		}
		*/
		total += m;
	}
	return (total >= m);
}

int32_t	main(void)
{
	int m, n;
	cin >> m >> n;

	ps	arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i].t >> arr[i].z >> arr[i].y;

	int	lo = 0, hi = (int)1e9, mid;

	while (hi > lo + 1)
	{
		mid = lo + (hi - lo) / 2;
		if (valid(arr, n, m, mid))
			hi = mid;
		else
			lo = mid;
	}
	cout << hi << "\n";
	for (int i = 0; i < n; i++)
		cout << arr[i].m << " ";
	cout << "\n";
}
