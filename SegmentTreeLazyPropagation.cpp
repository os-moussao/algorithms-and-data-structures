struct LazySegTree {
    vector<int> all;
    int n;
    vector<int> s;
    vector<int> lazy;
    int identity = 0;
 
    int fn(int a, int b){
        return a + b;
    }
    LazySegTree(int n) {
        this->n = n;
        s.assign(4 * n, identity);
        lazy.assign(4 * n, identity);
        all.assign(n, identity);
    }
    LazySegTree(vector<int> &a){
        n = a.size();
        all = a;
        s.resize(4 * n);
        lazy.resize(4 * n);
        build(1, 0, n - 1);
    }
    void    build(int node, int start, int end){
        if (start == end){
            s[node] = all[start];
            return ;
        }
        int mid = (start + end) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        s[node] = fn(s[2*node], s[2*node + 1]);
    }
    
    void    push_down(int node, int start, int end) {
        s[node] += lazy[node] * (end - start + 1);
        if (start != end){
            lazy[2 * node] += lazy[node];
            lazy[2 * node + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
 
    void    update(int node, int start, int end, int l, int r, int val){
        push_down(node, start, end);
        if (start > r ||  end < l) return ;
        if (start >= l && end <= r){
            lazy[node] += val;
            push_down(node, start, end);
            return ;
        }
        int mid = (start + end) / 2;
        update(2 * node, start, mid, l, r, val);
        update(2 * node + 1, mid + 1, end, l, r, val);
        s[node] = fn(s[2 * node], s[2 * node + 1]);
    }
    void    update(int l, int r, int val){
        update(1, 0, n - 1, l, r, val);
    }
    
    int query(int node, int start, int end, const int l, const int r){
        push_down(node, start, end);
        if (start > r || end < l) return identity;
        if (start >= l && end <= r) return s[node];
        int mid = (start + end) / 2;
        int left = query(2 * node, start, mid, l, r);
        int right = query(2 * node + 1, mid + 1, end, l, r);
        return fn(left, right);
    }
    int query(int l, int r){
        return query(1, 0, n - 1, l, r);
    }
};
 