// task: https://codeforces.com/contest/1216/problem/C
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
	
struct Rect {
	int x1, y1, x2, y2;
	Rect(int x1=0, int y1=0, int x2=0, int y2=0) : x1(x1), x2(x2), y1(y1), y2(y2) {}
	int area() {
		return (x2-x1)*(y2-y1);
	}
	Rect inter(Rect r) {
		int lx, rx, ly, ry;
		lx = max(x1, r.x1), rx = min(x2, r.x2);
		ly = max(y1, r.y1), ry = min(y2, r.y2);
		if (rx>lx && ry>ly) return Rect(lx, ly, rx, ry);
		return Rect();
	}
};
	
int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	Rect a(x1, y1, x2, y2);
	
	cin >> x1 >> y1 >> x2 >> y2;
	Rect b(x1, y1, x2, y2);
	
	cin >> x1 >> y1 >> x2 >> y2;
	Rect c(x1, y1, x2, y2);
	
	b = b.inter(a), c = c.inter(a);
	int areaa = b.area() + c.area() - b.inter(c).area();
	cout << (areaa == a.area() ? "NO\n": "YES\n");
}