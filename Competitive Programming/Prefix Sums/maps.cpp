// good tutorial for maps: https://www.youtube.com/watch?v=7mwgA9XFIEQ
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

#define int long long
#define double long double

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;

#define REP(i, a, n) for(int i = a; i < n; i++)
#define RREP(i, n, a) for(int i = n; i >= a; i--)
#define IETR(i, a, b) for(auto i = a; i != b; i++)
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


int32_t main()
{
	string test = "hello world my name is oussama";
	map <char, int> occ;

	// This also will work
	// REP(i, 0, test.L) occ[test[i]]++;
	REP(i, 0, test.L)
	{
		//This is how to check if a key exists in a map or not
		if (occ.find(test[i]) == occ.E)
			occ[test[i]] = 0;
		occ[test[i]]++;
	}

	// for (auto itr = occ.B; itr != occ.E; itr++)
	IETR(itr, occ.B, occ.E) {
		cout << itr->F << ss << itr->S << nn;
	}
}
