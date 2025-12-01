#include <bits/stdc++.h>
using namespace std;
#define ll long long

// SRC: https://usaco.guide/adv/persistent?lang=cpp#index-implementation
class PST {
  private:
  struct Node {
    ll val = 0;
    int l = 0, r = 0;
  };

  const int n;
  vector<Node> tree;
  int timer = 1;

  Node join(int l, int r) { return Node{tree[l].val + tree[r].val, l, r}; }

  int build(int tl, int tr) {
    if (tl == tr) {
      tree[timer] = {0, 0, 0};
      return timer++;
    }

    int mid = (tl + tr) / 2;
    tree[timer] = join(build(tl, mid), build(mid + 1, tr));

    return timer++;
  }

  int build(int tl, int tr, const vector<int> &arr) {
    if (tl == tr) {
      tree[timer] = {arr[tl], 0, 0};
      return timer++;
    }

    int mid = (tl + tr) / 2;
    tree[timer] = join(build(tl, mid, arr), build(mid + 1, tr, arr));

    return timer++;
  }

  int set(int v, int pos, int val, int tl, int tr) {
    if (tl == tr) {
      tree[timer] = {val, 0, 0};
      return timer++;
    }

    int mid = (tl + tr) / 2;
    if (pos <= mid) {
      tree[timer] = join(set(tree[v].l, pos, val, tl, mid), tree[v].r);
    } else {
      tree[timer] = join(tree[v].l, set(tree[v].r, pos, val, mid + 1, tr));
    }

    return timer++;
  }

  ll query(int v, int ql, int qr, int tl, int tr) {
    if (qr < tl || tr < ql) { return 0ll; }
    if (ql <= tl && tr <= qr) { return tree[v].val; }

    int mid = (tl + tr) / 2;
    return query(tree[v].l, ql, qr, tl, mid) +
           query(tree[v].r, ql, qr, mid + 1, tr);
  }

  public:
  PST(int n, int updates) : n(n), tree(2 * n + updates * (2 + ceil(log2(n)))) {}

  int build(const vector<int> &arr) { return build(0, n - 1, arr); }
  
  int build() { return build(0, n - 1); }

  int set(int root, int pos, int val) { return set(root, pos, val, 0, n - 1); }

  ll query(int root, int l, int r) { return query(root, l, r, 0, n - 1); }

  int add_copy(int root) {
    tree[timer] = tree[root];
    return timer++;
  }
};
