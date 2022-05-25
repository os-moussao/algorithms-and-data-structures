#pragma once

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
