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
#define double long double
#define endl '\n'

#define ALL(a) a.begin(), a.end()
#define RALL(a) a.rbegin(), a.rend()
#define YESORNO(x) cout << (x? "YES\n": "NO\n")
#define MAXVEC(vec) *max_element(ALL(vec))
#define MINVEC(vec) *min_element(ALL(vec))
#define getunique(vec) {sort(vec.begin(), vec.end()); vec.erase(unique(vec.begin(), vec.end()), vec.end());}
#define popcount(x) __builtin_popcountll(x);

template<class T> bool ckmin(T& a, const T b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T b) { return a < b ? a = b, 1 : 0; }
template<class T> bool ft_swap(T &mn, T &mx) {return mn > mx? (swap(mn, mx), 1): 0;}

#ifdef LOCAL
#include "debug.hpp"
#else
#define debug(x...)
#endif

vector<int> build_lps(string p) {
	int sz = p.size();
	vector<int> lps;
	lps.assign(sz + 1, 0);
	int j = 0;
	lps[0] = 0;
	for(int i = 1; i < sz; i++) {
	while(j >= 0 && p[i] != p[j]) {
		if(j >= 1) j = lps[j - 1];
		else j = -1;
	}
	j++;
	lps[i] = j;
	}
	return lps;
}
// returns matches in vector ans in 0-indexed
vector <int> kmp(vector<int> lps, string s, string p) {
	vector <int> ans;
	int psz = p.size(), sz = s.size();
	int j = 0;
	for(int i = 0; i < sz; i++) {
	while(j >= 0 && p[j] != s[i])
		if(j >= 1) j = lps[j - 1];
		else j = -1;
	j++;
	if(j == psz) {
		j = lps[j - 1];
		// pattern found in string s at position i-psz+1
		ans.push_back(i - psz + 1);
	}
	// after each loop we have j=longest common suffix of s[0..i] which is also prefix of p
	}
	return ans;
}

vector <int> kmp(string str, string pattern) {
	return kmp(build_lps(pattern), str, pattern);
}

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

void solve()
{
	string s; cin >> s;
	int n; cin >> n;
	vector <pair <pair <int, int>, int>> v;
	// n*(s.length() + p.length())
	for (int i = 0; i < n; i++) {
		string p; cin >> p;
		vector <int> occ = kmp(s, p);
		for (int pos: occ) {
			v.push_back({{pos, pos+p.length()-1}, i+1});
		}
	}

	if (v.empty()) {
		cout << -1 << endl;
		return ;
	}

	sort(ALL(v));
	vector <int> tmp(v.size());
	for (int i = 0; i < tmp.size(); i++) {
		tmp[i] = v[i].first.second;
	}
	SegmentTree seg(tmp);

	// vector <pair<int, int>> ans;

	vector <pair<int, int>> ans;
	int end = -1;
	for (int i = 0; end < (int)(s.length())-1; ) {
		int lo = 0, hi = (int)(v.size())-1, pos = -1;
		while (lo <= hi) {
			int mid = lo + (hi-lo)/2;
			int x = v[mid].first.first;
			if (x <= end+1) {
				lo = mid+1;
				pos=mid;
			} else {
				hi = mid-1;
			}
			// debug(mid, end, pos);
		}
		// debug(pos);
		if (pos==-1) {
			cout << -1 << endl;
			return ;
		}
		pos = seg.query(0, pos).second;
		// debug(pos);
		int tmp = v[pos].first.second;
		if (tmp <= end) {
			cout << -1 << endl;
			return ;
		}
		end = tmp;
		// debug(end);
		ans.push_back({v[pos].second, v[pos].first.first + 1});
	}

	cerr << v.size() << ' ' << s.length() << endl;
	cout << ans.size() << endl;
	for (pair <int, int> &p: ans) {
		cout << p.first << ' ' << p.second << endl;
	}
	// for (int i = )
	// for (int i = 0; i < v.size(); i++) {
	// 	cerr << v[i].second << ' ' << v[i].first.first << ' ' << v[i].first.second << endl;
	// }
	// cerr << endl;
	// debug(tmp);
}

void preprocessing() {}

bool MULTY_TEST_CASES = 1;

int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << setprecision(20);
	cout << fixed;

	preprocessing();

	int t = 1;
	if (MULTY_TEST_CASES) cin >> t;

	while (t--) {
		solve();
	}
}