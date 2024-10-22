class FenwickTree {
  const int IDENTITY = 0;
  int fn(int a, int b) { return a+b; }
  int revFn(int a, int b) { return a-b; }
  int diff(int i, int x) { return revFn(x, a[i]); }
  vector<int> bit, a;
public:
  FenwickTree(int n): bit(n, IDENTITY), a(n, IDENTITY) {}
  FenwickTree(vector<int> &a): bit(SZ(a), IDENTITY), a(SZ(a), IDENTITY) {
    for (int i = 0; i < SZ(a); i++) {
      this->update(i, a[i]);
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
    return l > 0 ? revFn(query(r), query(l-1)): query(r);
  }
};