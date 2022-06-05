// task: https://leetcode.com/problems/longest-valid-parentheses/

typedef long long ll;

struct segTree {
	typedef ll T;
	static const T identity = 1e18;
	T fn(T a, T b) { return min(a, b); } // (any associative fn)
	vector<T> s; int n;
	segTree(int n = 0, T def = identity) : s(4*n, def), n(n) {}
	segTree(vector <T> &a) : s(4*a.size()), n(a.size()) {
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

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        int pre[n+1]; pre[0] = 0;
        segTree seg(n+1); seg.update(0, 0);
        map<ll, vector <ll>> pos;
        pos[0].push_back(0);
        for (int i = 1; i <= n; i++) {
            pre[i] = pre[i-1];
            pre[i] += s[i-1] == '('? 1: -1;
            pos[pre[i]].push_back(i);
            seg.update(i, pre[i]);
        }
        cerr << endl;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            vector <ll> occ = pos[pre[i]];
            int lo = 0, hi = lower_bound(occ.begin(), occ.end(), i) - occ.begin(), mid, ind = -1;
            if (hi == lo) continue ;
            while (lo <= hi) {
                mid = lo + (hi - lo) / 2;
                if (seg.query(occ[mid], i) >= pre[i]) {
                    hi = mid - 1;
                    ind = occ[mid];
                }
                else {
                    lo = mid + 1;
                }
            }
            if (ind != -1) {
                ans = max(ans, i-ind);
            }
        }
        return ans;
    }
};