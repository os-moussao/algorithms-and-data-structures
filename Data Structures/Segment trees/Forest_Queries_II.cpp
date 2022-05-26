// task: https://cses.fi/problemset/task/1739/
#include <bits/stdc++.h>

using namespace std;
#define int long long
#define double long double
#define endl '\n'

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef vector<bool> vb;

#define MP(x, y) make_pair(x, y)
#define ALL(a) a.begin(), a.end()
#define RALL(a) a.rbegin(), a.rend()
#define YESORNO(x) cout << (x? "YES\n": "NO\n")
#define MAXVEC(vec) *max_element(ALL(vec))
#define MINVEC(vec) *min_element(ALL(vec))
#define getunique(vec) {sort(vec.begin(), vec.end()); vec.erase(unique(vec.begin(), vec.end()), vec.end());}

template<class T> bool ckmin(T& a, const T b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T b) { return a < b ? a = b, 1 : 0; }
template<class T> bool ft_swap(T &mn, T &mx) {return mn > mx? (swap(mn, mx), 1): 0;}

class segTree2d {
	int lenx;
	int leny;
	vector<vector<int>> all;
	vector<vector<int>> seg;
	static const int identity = 0;
	int fn(int a, int b) {return a + b;}
public:
	segTree2d(){}
	segTree2d(vector<vector<int>> inp) {
		lenx = inp.size();
		leny = inp[0].size();
		all = inp;
		seg.resize(4 *lenx);
		for (int i = 0; i < 4*lenx; i++)
			seg[i].resize(4*leny);
		buildx(1,1,0,lenx-1,0,leny-1);
	}
	// rows range: [lx , rx]
	// columns range: [ly , ry]
	int query(int lx,int rx,int ly,int ry) {
		return queryx(1,0,lenx-1,lx,rx,ly,ry);
	}
	// Update (x, y)
	void update(int x,int y, int val) {
		updatex(1,0,lenx-1,x,y,val);
	}
private:
	void buildy(int idx, int idy, int lx, int rx, int ly, int ry)
	{
		if (ly==ry)
		{
			if (lx == rx)
				seg[idx][idy]= all[lx][ly];
			else
				seg[idx][idy] = fn(seg[2*idx][idy] , seg[2*idx+1][idy]);
		}
		else
		{
			int midy=(ly+ry)/2;
			buildy(idx,2*idy,lx,rx,ly,midy);
			buildy(idx,2*idy+1,lx,rx,midy+1,ry);
			seg[idx][idy] = fn(seg[idx][2*idy], seg[idx][2*idy+1]);
		}
	}
	void buildx(int idx, int idy, int lx, int rx, int ly, int ry)
	{
		if (lx != rx)
		{
			int midx = (lx+rx)/2;
			buildx(2*idx,idy,lx,midx,ly,ry);
			buildx(2*idx+1,idy,midx+1,rx,ly,ry);
		}
		buildy(idx,idy,lx,rx,ly,ry);
	}
	int queryy(int idx, int idy, int tly,int tryy, int ly,int ry)
	{
		if (tly > ry || tryy < ly)
			return identity;
		if (tly >= ly && tryy <= ry)
			return seg[idx][idy];
		int tmy = (tly+tryy)/2;
		return fn(queryy(idx,2*idy,tly,tmy,ly,ry), queryy(idx,2*idy+1,tmy+1,tryy,ly,ry));
	}
	int queryx(int idx, int tlx,int trx, int lx,int rx,int ly,int ry)
	{
		if (tlx > rx || trx<lx)
			return identity;
		if (tlx >= lx && trx <= rx)
			return queryy(idx,1,0,leny-1,ly,ry);
		int tmx=(tlx+trx)/2;
		return fn(queryx(2*idx,tlx,tmx,lx,rx,ly,ry), queryx(2*idx+1,tmx+1,trx,lx,rx,ly,ry));
	}
	void updatey(int idx, int tlx, int trx, int idy, int tly, int tryy, int y, int val)
	{
		if (tly == tryy)
		{
			if (tlx == trx)
				seg[idx][idy]=val;
			else
				seg[idx][idy] = fn(seg[2*idx][idy], seg[2*idx+1][idy]);
		}
		else
		{
			int tmy=(tly+tryy)/2;
			if (y <= tmy)
				updatey(idx,tlx,trx,2*idy,tly,tmy,y,val);
			else
				updatey(idx,tlx,trx,2*idy+1,tmy+1,tryy,y,val);
			seg[idx][idy] = fn(seg[idx][2*idy], seg[idx][2*idy+1]);
		}
	}
	void updatex(int idx, int tlx, int trx, int x, int y, int val)
	{
		if (tlx != trx)
		{
			int tmx = (tlx+trx)/2;
			if (x <= tmx)
				updatex(2*idx,tlx,tmx,x,y,val);
			else
				updatex(2*idx+1,tmx+1,trx,x,y,val);
		}
		updatey(idx, tlx, trx,1,0,leny-1,y, val);
	}
};

int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin>> n >> m;
	vvi arr(n, vi(n));
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < n;j++) arr[i][j] = (s[j] == '*');
	}
	segTree2d seg(arr);
	while (m--) {
		int q; cin >> q;
		if (q==1) {
			int x, y; cin >> x >> y;
			--x, --y;
			arr[x][y] = !(arr[x][y]);
			seg.update(x, y, arr[x][y]);
		}
		else {
			int x, xx, y, yy;
			cin >> x >> y >> xx >> yy;
			--x, --y, --xx, --yy;
			ft_swap(x, xx); ft_swap(y, yy);
			cout << seg.query(x, xx, y, yy) << endl;
		}
	}
}