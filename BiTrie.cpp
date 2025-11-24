// src: https://github.com/ShahjalalShohag/code-library/blob/main/Data%20Structures/Trie.cpp
struct Trie {
  static const int B = 31;
  struct node {
    node* nxt[2];
    int sz;
    node() {
      nxt[0] = nxt[1] = NULL;
      sz = 0;
    }
  } *root;
  Trie() {
    root = new node();
  }
  void insert(int val) {
    node* cur = root;
    cur -> sz++;
    for (int i = B - 1; i >= 0; i--) {
      int b = val >> i & 1;
      if (cur -> nxt[b] == NULL) cur -> nxt[b] = new node();
      cur = cur -> nxt[b];
      cur -> sz++;
    }
  }
  void erase(int val) {
    if (get_min(val)) return ; // value not present
    node *cur = root;
    cur -> sz--;
    for (int i = B - 1; i >= 0; i--) {
      int b = val >> i & 1;
      node* nxtNode = cur -> nxt[b];
      nxtNode -> sz--;
      if (nxtNode -> sz == 0) {
        cur -> nxt[b] = NULL;
        del(nxtNode);
        return;
      }
      cur = nxtNode;
    }
  }
  int query(int x, int k) { // number of values s.t. val ^ x < k
    node* cur = root;
    int ans = 0;
    for (int i = B - 1; i >= 0; i--) {
      if (cur == NULL) break;
      int b1 = x >> i & 1, b2 = k >> i & 1;
      if (b2 == 1) {
        if (cur -> nxt[b1]) ans += cur -> nxt[b1] -> sz;
        cur = cur -> nxt[!b1];
      } else cur = cur -> nxt[b1];
    }
    return ans;
  }
  int get_max(int x) { // returns maximum of val ^ x
    node* cur = root;
    int ans = 0;
    for (int i = B - 1; i >= 0; i--) {
      int k = x >> i & 1;
      if (cur -> nxt[!k]) cur = cur -> nxt[!k], ans <<= 1, ans++;
      else cur = cur -> nxt[k], ans <<= 1;
    }
    return ans;
  }
  int get_min(int x) { // returns minimum of val ^ x
    node* cur = root;
    int ans = 0;
    for (int i = B - 1; i >= 0; i--) {
      int k = x >> i & 1;
      if (cur -> nxt[k]) cur = cur -> nxt[k], ans <<= 1;
      else cur = cur -> nxt[!k], ans <<= 1, ans++;
    }
    return ans;
  }
  void del(node* cur) {
    for (int i = 0; i < 2; i++) if (cur -> nxt[i]) del(cur -> nxt[i]);
    delete(cur);
  }
  ~Trie() { del(root); }
};

// Memory optimized version
struct Trie {
  static const int B = 31;
  int sz = 1;
  struct node {
    int32_t nxt[2];
    int sz;
    node() {
      nxt[0] = nxt[1] = 0;
      sz = 0;
    }
  };
  vector<node> data;
  int new_node() {
    return ++sz;
  }
  Trie(int mxSz) {
    data.assign(mxSz, node());
    sz = 1;
  }
  void insert(int val) {
    int curr = 1;
    data[curr].sz++;
    for (int i = B - 1; i >= 0; i--) {
      int b = val >> i & 1;
      if (data[curr].nxt[b] == 0) data[curr].nxt[b] = new_node();
      curr = data[curr].nxt[b];
      data[curr].sz++;
    }
  }
  int query(int x, int k) { // number of values s.t. val ^ x < k
    int cur = 1;
    int ans = 0;
    for (int i = B - 1; i >= 0; i--) {
      if (cur == 0) break;
      int b1 = x >> i & 1, b2 = k >> i & 1;
      if (b2 == 1) {
        if (data[cur].nxt[b1]) ans += data[data[cur].nxt[b1]].sz;
        cur = data[cur].nxt[!b1];
      } else cur = data[cur].nxt[b1];
    }
    return ans;
  }
};