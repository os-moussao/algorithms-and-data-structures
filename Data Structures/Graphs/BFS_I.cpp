#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

#define int long long
#define double long double

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef pair<double, double> pdd;
typedef pair<char, int> pci;
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
#define MP(x, y) make_pair(x, y)
#define PB push_back
#define PF push_front
#define B begin()
#define RB rbegin()
#define E end()
#define RE rend()
#define ALL(a) a.B, a.E
#define RALL(a) a.RB, a.RE
#define nn '\n'
#define ss ' '

// BFS Tutorial from Reducible
// https://www.youtube.com/watch?v=xlVX7dXLS64&ab_channel=Reducible
// Solving the second problem of this video (connected pixels)

vpi get_neighbors(vvi &img, pi elem, int color)
{
	int i = elem.F, j = elem.S;
	vpi neighb {
		MP(i - 1, j),
		MP(i + 1, j),
		MP(i, j - 1),
		MP(i, j + 1)
	};
	vpi res;
	for (int k = 0; k < 4; k++) {
		i = neighb[k].F;
		j = neighb[k].S;
		if (i >= 0 && j >= 0 && i < img.SZ && j < img[0].SZ && img[i][j] == color)
			res.PB(MP(i, j));
	}
	return res;
}

void flood_fill(vvi &img, pi start, int new_color)
{
	queue<pi> q;
	q.push(start);
	map<pi, bool> visited;
	int color = img[start.F][start.S];

	while (q.SZ > 0) {
		pi curr = q.front();
		q.pop();
		visited[curr] = 1;
		img[curr.F][curr.S] = new_color;
		vpi neighbors = get_neighbors(img, curr, color);
		for (int i = 0; i < neighbors.SZ; i++) {
			if (!visited[neighbors[i]])
				q.push(neighbors[i]);
		}
	}
}

int32_t main()
{
	vvi img {
		{0, 2, 0, 1, 0},
		{0, 1, 2, 0, 0},
		{2, 2, 2, 2, 0},
		{0, 2, 0, 2, 0},
		{0, 1, 0, 1, 2}
	};
	for (int i = 0; i < img.SZ; i++) {
		for (int j = 0; j < img[0].SZ; j++) {
			cout << img[i][j] << ss;
		}
		cout << nn;
	}
	cout << nn;
	flood_fill(img, MP(2, 0), 7);
	for (int i = 0; i < img.SZ; i++) {
		for (int j = 0; j < img[0].SZ; j++) {
			cout << img[i][j] << ss;
		}
		cout << nn;
	}
}
