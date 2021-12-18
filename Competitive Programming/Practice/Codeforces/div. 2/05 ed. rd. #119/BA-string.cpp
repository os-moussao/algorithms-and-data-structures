/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BA-string.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 18:26:41 by omoussao          #+#    #+#             */
/*   Updated: 2021/12/18 19:56:12 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

#define not_fd string::npos

void solve()
{
	int n, k, x;
	string s;
	cin >> n >> k >> x >> s;



	string a;
	int i = s.L - 1;
	x--;
	while (i >= 0 && x)
	{
		if (s[i] == '*')
		{
			int kk = 0;
			while (x && kk < k)
			{
				//cout << 'b';
				a.insert(0, "b");
				kk++;
				x--;
			}
		}
		else
			a.insert(0, "a");
		i--;
	}
	if (x == 0)
	{
		while (i >= 0)
		{
			if (s[i] != '*') a.insert(0, "a");
			i--;
		}
	}
	else
	{

	}
	cout << a << nn;
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
