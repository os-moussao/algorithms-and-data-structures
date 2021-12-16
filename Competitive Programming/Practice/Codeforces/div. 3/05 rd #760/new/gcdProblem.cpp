#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <numeric>
#include <algorithm>
#include <math.h>

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
 
vector<int> factors(int n)
{
    vector<int> v;
	int sq = sqrt(n);
 
    for (int i = 2; i <= sq; i++)
	{
        if (n % i == 0)
		{
           	v.push_back(i);
            while (n && n / i)
				n /= i;
        }
    }
    return v;
}
 
/*
int gcd(int a, int b)
{
    // Everything divides 0
    if (a == 0)
       return b;
    if (b == 0)
       return a;
 
    // base case
    if (a == b)
        return a;
 
    // a is greater
    if (a > b)
        return gcd(a-b, b);
    return gcd(a, b-a);
}*/
 
int gcd(int a, int b)
{
    // do until the two numbers become equal
    while (a != b)
    {
        // replace the larger number by its difference with the smaller number
        if (a > b) {
            a = a - b;
        }
        else {
            b = b - a;
        }
    }
 
    return a;        // or `b` (since both are equal)
}
 
void solve()
{
	int n;
	cin >> n;
	vi v = factors(n);
 
	FOR(i, v.SZ) //cout << "c = " << v[i] << "\t n/c - 1 = \t" << n / v[i] - 1 << nn;
	{
		int c, x, y, z;
 
		c = v[i];
		z = n / c - 1;
		REP(j, 2, z / 2)
		{
			if (gcd(j, z - j) == 1)
			{
				x = j, y = z - j;
				cout << c*x << ss << c*y << ss << c << nn;
				return ;
			}
		}
	}
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
