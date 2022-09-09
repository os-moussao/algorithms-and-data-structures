#pragma once

// min and max queries with position
// template copies from: https://github.com/jalalium/cpTemplates/blob/master/segmentTree.cpp
// and then updated to get the position
class SegmentTree{
	int identity = (int)(-1e18);
	int fn(int a, int b) { return max(a, b); }
	int len;
	vector <int> all;
	vector <pair<int, int>> seg;
	public:
	SegmentTree(){}
	SegmentTree(vector <int> inp)
	{
		len = inp.size();
		all = inp;
		seg.resize(4*len);
		build(1,0,len-1);
	}
	void build(int id, int l, int r)
	{
		if (l==r)
		{
			seg[id].first = all[l];
			seg[id].second = l;
			return ;
		}
		int mid=(l+r)/2;
		build(2*id,l,mid);
		build(2*id+1,mid+1,r);
		if (fn(seg[2*id].first,seg[2*id+1].first) == seg[2*id].first) {
			seg[id].first = seg[2*id].first;
			seg[id].second = seg[2*id].second;
		} else {
			seg[id].first = seg[2*id+1].first;
			seg[id].second = seg[2*id+1].second;
		}
	}
	pair<int, int> query(int id, int l, int r, int sl, int sr)
	{
		if (r < sl || sr < l)
			return {identity, -1};
		if (sl <= l && sr >= r)
			return seg[id];
		int mid = (l+r)/2;
		pair<int, int> a = query(2*id,l,mid,sl,sr);
		pair<int, int> b = query(2*id+1,mid+1,r,sl,sr);
		if (fn(a.first, b.first) == a.first) return a;
		else return b;
	}
	pair<int, int> query(int l,int r)
	{
		return query(1,0,len-1,l,r);
	}
};
