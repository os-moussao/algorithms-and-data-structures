// from kactl
struct SegTree {
	typedef int T;
	static const T identity = 0;
	T fn(T a, T b) { return a + b; } // (any associative fn)
	vector<T> s; int n;
	SegTree(int n = 0, T def = identity) : s(2*n, def), n(n) {}
	SegTree(vector <T> &a) : s(2*a.size()), n(a.size()) {
		for (int i = 0; i < n; i++) update(i, a[i]);
	}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = fn(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int b, int e) { // query [b, e]
		T ra = identity, rb = identity; e++;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = fn(ra, s[b++]);
			if (e % 2) rb = fn(s[--e], rb);
		}
		return fn(ra, rb);
	}
};


// seg tree recursive implementation
struct Tree {
  typedef int T;
  static constexpr T identity = 0;
  int n;
  vector<T> tree;

  T fn(T a, T b) { return a + b; }

  Tree(vector<T> &a) {
    n = a.size();
    tree.resize(4 * n);
    build(1, 0, n - 1, a);
  }

  Tree(int n): n(n) {
    tree.assign(4 * n, identity);
  }
  
  void build(int idx, int l, int r, vector<T> &a) {
    if (l == r) {
      tree[idx] = a[l];
      return ;
    }
    int mid = (l+r) / 2;
    build(idx * 2, l, mid, a);
    build(idx * 2 + 1, mid+1, r, a);
    tree[idx] = fn(tree[2*idx],tree[2*idx+1]);
  }

  void update(int idx, int l, int r, int pos, T val) {
    if (l == r) {
      tree[idx] = val;
      return ;
    }
    if (pos < l || pos > r) return ;
    int mid = (l+r)/2;
    update(idx*2, l, mid, pos, val);
    update(idx*2+1, mid+1, r, pos, val);
    tree[idx] = fn(tree[2*idx], tree[2*idx+1]);
  }

  void update(int pos, T val) {
    return update(1, 0, n-1, pos, val);
  }

  T query(int idx, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) {
      return tree[idx];
    }
    if (l > qr || r < ql) {
      return identity;
    }
    int mid = (l + r) / 2;
    return fn(query(2*idx, l, mid, ql, qr), query(2*idx+1, mid+1, r, ql, qr));
  }

  T query(int l, int r) {
    return query(1, 0, n-1, l, r);
  }
};


// from https://github.com/jalalium/cpTemplates
class SegTree2d {
	int lenx;
	int leny;
	vector<vector<int>> all;
	vector<vector<int>> seg;
	static const int identity = 0;
	int fn(int a, int b) {return a + b;}
public:
	SegTree2d(){}
	SegTree2d(vector<vector<int>> inp) {
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
	int query(pair<int,int> a, pair <int, int> b) {
		return query(a.first, b.first, a.second, b.second);
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

