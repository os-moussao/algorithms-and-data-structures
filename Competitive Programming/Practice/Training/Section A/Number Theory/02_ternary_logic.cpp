// https://codeforces.com/contest/136/problem/B
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

string int_ter(string ter, int n)
{
	if (n >= 3)
		ter = int_ter(ter, n / 3);
	ter += (char)((n % 3) + '0');
	return ter;
}

string tor(string a, string b)
{
	string res = "";
	FOR(i, a.L)
		res += (char)((a[i] - '0' + b[i] - '0') % 3 + '0');
	return res;
}

int	ter_int(string ter)
{
	int res = 0;
	FOR(i, ter.L)
		res = res * 3 + (int)(ter[i] - '0');
	return res;
}

void match(string &aa, string &bb)
{
	if (aa.L < bb.L)
	{
		while (aa.L < bb.L)
			aa.insert(0, "0");
	}
	else {
		while (bb.L < aa.L)
			bb.insert(0, "0");
	}
}

void solve()
{
	int a, b;
	cin >> a >> b;
	string aa = int_ter("", a), bb = int_ter("", b);
	match(aa, bb);
	b = ter_int(tor(aa, bb));
	bb = int_ter("", b);
	match(aa, bb);
	cout << ter_int(tor(aa, bb)) << nn;
}

int32_t main()
{
	int t;

	//cin >> t;
	t = 1;
	while (t--) {
		solve();
	}
	return 0;
}
