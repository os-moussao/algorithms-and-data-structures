#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;

#define int long long
#define double long double

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<char, int> pci;
typedef vector<pii> vpii;
typedef vector<pdd> vpdd;
typedef vector<pci> vpci;

#define REP(i, a, n) for(int i = a; i < n; i++)
#define FOR(i, n) for(int i = 0; i < n; i++)
#define RREP(i, n, a) for(int i = n; i >= a; i--)
#define RFOR(i, n) for(int i = n; i >= 0; i--)
#define ITER(i, a, b) for(auto i = a; i != b; i++)
#define SZ size()
#define L length()
#define F first
#define S second
#define PB push_back
#define PF push_front
#define B begin()
#define E end()
#define nn '\n'
#define ss ' '

int solve1(int n, int k, vi arr)
{
	int ans = 0;
	int i = n - 1;
	while (i > 0 && k--)
	{
		ans += arr[i - 1] / arr[i];
		i -= 2;
	}
	while (i >= 0)
		ans += arr[i--];
	return ans;
}

int solve2(int n, int k, vi arr)
{
	int ans = 0;
	int i = 0, j = n - 1;
	while (i < j && k--)
	{
		ans += arr[i] / arr[j];
		i++, j--;
	}
	while (i <= j)
		ans += arr[i++];
	return ans;
}

int solve3(int n, int k, vi arr)
{
	int ans = 0;
	int i = n - 1;

	while (k--)
	{
		ans += arr[i - 2] / arr[i];
		i--;
	}
	int j = 0;
	while (j < i - 2)
		ans += arr[j++];
	return ans;
}

int32_t main()
{
	int t;

	cin >> t;
	//t = 1;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vi arr(n);
		FOR(i, n) cin >> arr[i];
		sort(arr.B, arr.E);

		cout << min({solve1(n, k, arr), solve2(n, k, arr), solve3(n, k, arr)}) << nn;
	}
	return 0;
}
