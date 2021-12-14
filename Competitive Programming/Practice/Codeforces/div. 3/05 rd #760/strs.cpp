#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <cmath>

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
typedef vector<string> vs;

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
void solve()
{
	int n;
	cin >> n;

	string res = "";
	int dups = 0;
	char c = 0;
	FOR(i, n- 2)
	{
		string sb;
		cin >> sb;

		if (i == 0)
			res.insert(0, sb);
		else
		{
			if ((res[res.L - 1] + sb[0]).compare(sb) != 0)
				res.insert(res.B + res.L, sb[0]);
			else if ((res[res.L - 1] + sb[1]).compare(sb) != 0)
				res.insert(res.B + res.L, sb[1]);
		}
	}
	while (res.L < n)
		res.insert(res.B + res.L, 'a');
	cout << res << nn;
}*/

void solve()
{
	int n;
	cin >> n;


	int l = 0;
	char c;
	FOR(i, n- 2)
	{
		string sb;
		cin >> sb;

		if (i == 0)
		{
			cout << sb;
			c = sb[1];
			l += 2;
		}
		else if (i == n - 3 && l < n - 2)
		{
			cout << sb;
			l += 2;
		}
		else
		{
			string s1; s1 += c; s1 += sb[0];
			string s2; s2 += c; s2 += sb[1];
			if (s1.compare(sb) == 0)
				cout << sb[0], c = sb[0];
			else if (s2.compare(sb) == 0)
				cout << sb[1], c = sb[1];
			else
			{
				cout << sb;
				c = sb[1];
				l++;
			}
			l++;
		}
		if (i == n - 3)
			c = sb[1];
	}
	while (l < n)
		cout << c, l++;
	cout << nn;
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
