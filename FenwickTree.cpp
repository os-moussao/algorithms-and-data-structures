class FenwickTree {
  const int IDENTITY = 0;
  int fn(int a, int b) { return a+b; }
  int invFn(int a, int b) { return a-b; }
  int diff(int i, int x) { return invFn(x, a[i]); }
  vector<int> bit, a;
public:
  FenwickTree(int n): bit(n, IDENTITY), a(n, IDENTITY) {}
  FenwickTree(vector<int> &a): bit(SZ(a), IDENTITY), a(a) {
    for (int i = 0; i < SZ(a); i++) {
      bit[i] = fn(bit[i], a[i]);
      int r = i | (i+1);
      if (r < SZ(a)) bit[r] = fn(bit[r], bit[i]);
    }
  }
  void update(int i, int x) {
    int delta = diff(i,x);
    a[i] = x;
    for (int j = i; j < SZ(a); j |= (j+1)) {
      bit[j] = fn(bit[j], delta);
    }
  }
  int query(int r) {
    int res = IDENTITY;
    for (;r >= 0; r = (r & (r+1)) - 1) {
      res = fn(res, bit[r]);
    }
    return res;
  }
  int query(int l, int r) {
    return l == r ? a[l]: l > 0 ? invFn(query(r), query(l-1)): query(r);
  }
};

// Kactl
struct FT {
	vector<int> s;
	FT(int n) : s(n) {}
	void update(int pos, int dif) { // a[pos] += dif
		for (; pos < s.size(); pos |= pos + 1) s[pos] += dif;
	}
	int query(int pos) { // sum of values in [0, pos)
		int res = 0;
		for (; pos > 0; pos &= pos - 1) res += s[pos-1];
		return res;
	}
	int lower_bound(int sum) {// min pos st sum of [0, pos] >= sum
		// Returns n if no sum is >= sum, or -1 if empty sum is.
		if (sum <= 0) return -1;
		int pos = 0;
		for (int pw = 1 << 25; pw; pw >>= 1) {
			if (pos + pw <= s.size() && s[pos + pw-1] < sum)
				pos += pw, sum -= s[pos-1];
		}
		return pos;
	}
};