// task: https://codeforces.com/contest/1555/problem/B
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
	
struct Rect {
	int x1, y1, x2, y2;
	Rect(int x1=0, int y1=0, int x2=0, int y2=0) : x1(x1), x2(x2), y1(y1), y2(y2) {}
	int area() { return w()*h(); }
	int w() { return x2-x1; }
	int h() { return y2-y1; }
	Rect inter(Rect r) {
		int lx, rx, ly, ry;
		lx = max(x1, r.x1), rx = min(x2, r.x2);
		ly = max(y1, r.y1), ry = min(y2, r.y2);
		if (rx>=lx && ry>=ly) return Rect(lx, ly, rx, ry);
		return Rect();
	}
};
	
int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		int H, W; cin >> W >> H;
		int x1, y1, x2, y2; cin>> x1 >> y1 >> x2 >> y2;
		Rect r(x1, y1, x2, y2);
		int h, w; cin >> w >> h;
		if (h+r.h() > H && w + r.w() > W) {
			cout << -1 << endl;
			continue;
		}
		int ans = 1e9;
		if (h+r.h() <= H) {
			ans = min({ans, min(max((int)0, r.y2-H+h), max((int)0, h-r.y1))});
		}
		if (w + r.w() <= W) {
			ans = min({ans, min(max((int)0, r.x2-W+w), max((int)0, w-r.x1))});
		}
		cout << setprecision(9) << fixed << 1.*ans << endl;
	}
}