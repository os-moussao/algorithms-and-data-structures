#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <math.h>
#include <set>

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
/*
int mysq(int n)
{

}*/

void solve()
{
	int n;
	cin >> n;
	//int sq = (int)sqrt(n);
	int i = 1;

	//vi arr;
	map<int , int> hash;
	int ans = 0;
	while (i * i <= n)
	{
		if (!hash[i*i]) ans++; hash[i*i] = 1;
		if (i*i*i <= n && !hash[i*i*i])
		{
			ans++;
			hash[i*i*i] = 1;
		}
		i++;
	}
	//sort(arr.B, arr.E);
	//set<int> st(arr.B, arr.E);
	cout << ans << nn;
}

int32_t main()
{
	int t;

	cin >> t;
	//t = 1;
	while (t--) {
		solve();
	}
	return 0;
}
