#include <bits/stdc++.h>
using namespace std;

// answer query number of elements in [l, r] <= x
typedef int T;
struct Node {
  vector<T> v;
  Node(Node &nodeA, Node &nodeB) {
    vector<T> &a = nodeA.v, &b = nodeB.v;
    v.reserve(a.size() + b.size());
    int ai = 0, bi = 0;
    while (ai < a.size() && bi < b.size()) {
      if (a[ai] < b[bi]) v.push_back(a[ai++]);
      else v.push_back(b[bi++]);
    }
    while (ai < a.size()) v.push_back(a[ai++]);
    while (bi < b.size()) v.push_back(b[bi++]);
  };
  Node(vector<T> &a): v(a) {}
  Node(T x) { v = vector<T>(1, x); }
  Node() {}
};

const Node identity = Node(0);
struct MST {
  int n;
  vector<Node> tree;
  vector<T> a;
  MST(int n): n(n) {
    tree.resize(4*n, identity);
  }
  MST(vector<T> &a): n(a.size()), a(a) {
    tree.resize(4*n);
    build(1, 0, n - 1);
  }
  void build(int idx, int l, int r) {
    if (l == r) {
      tree[idx] = Node(a[l]);
      return ;
    }
    int mid = (l + r) / 2;
    build(2*idx, l, mid);
    build(2*idx+1, mid+1, r);
    tree[idx] = Node(tree[2*idx], tree[2*idx+1]);
  };

  // number of elements less than or equal to val in [ql, ar]
  // in O(log^2)
  int query(int idx, int l, int r, int ql, int qr, T val) {
    if (ql > r || qr < l) {
      return 0;
    }
    if (l >= ql && r <= qr) {
      vector<T> &arr = tree[idx].v;
      int ans = upper_bound(arr.begin(), arr.end(), val) - arr.begin();
      return ans;
    }
    int mid = (l+r)/2;
    int ansL = query(2*idx, l, mid, ql, qr, val);
    int ansR = query(2*idx+1, mid+1, r, ql, qr, val);
    return ansL + ansR;
  }

  // number of elements less than or equal to val in [l, r]
  // in O(log^2)
  int query(int l, int r, T val) {
    return query(1, 0, n - 1, l, r, val);
  }
};