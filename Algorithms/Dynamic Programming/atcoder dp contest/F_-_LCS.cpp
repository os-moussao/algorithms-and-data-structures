#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cstdint>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <deque>

using namespace std;
#define int long long
#define endl '\n'

template<class T> bool ckmax(T& a, const T b) { return a <= b ? a = b, 1 : 0; }

struct vec {
	int x, y, z;
};

int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s, t; cin >> s >> t;
	int n = s.size(), m = t.size();
	int D[3][2] = {{-1, -1}, {-1, 0}, {0, -1}};
	vec dp[n+1][m+1];
	memset(dp, 0, sizeof dp);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int x, y, z = dp[i][j].z;
			if (s[i-1] == t[j-1]) {
				if (ckmax(z, dp[i-1][j-1].z + 1)) {
					x = i-1;
					y = j-1;
				}
			}
			if (ckmax(z, dp[i-1][j].z)) {
				x = i-1;
				y = j;
			}
			if (ckmax(z, dp[i][j-1].z)) {
				x = i;
				y = j-1;
			}
			dp[i][j] = {x, y, z};
			// cerr << "{" << dp[i][j].x << "," << dp[i][j].y << "," << dp[i][j].z << "}" << " ";
		}
		// cerr << endl;
	}
	string ret;
	int i = n, j = m;
	while (i!=0&&j!=0) {
		int x = dp[i][j].x;
		int y = dp[i][j].y;
		if (dp[x][y].z < dp[i][j].z) ret += s[i-1];
		i = x, j = y;
	}
	reverse(ret.begin(), ret.end());
	cout << ret << endl;
}