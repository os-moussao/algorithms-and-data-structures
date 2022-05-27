#pragma once

typedef int T;
struct node {
    T val;
    T setAint;
    T increment;
    bool setAintValid;
    node() {
       val = 0; //* set to identity
       setAintValid = 0;
       increment = 0;
    }
    void reset() {
       setAintValid = 0;
	   increment = 0;
    }
};
 
class Segtree {
    int range;
    vector<node> tree;
	T identity = 0; //* set to identity
	T f(T a, T b) { return a + b; } //* set function 

public:
    Segtree(vector<T>& v) {
        range = v.size();
        tree.assign(4*range, node());
        build_recur(v, 0, range-1, 0);
    }

    T query(int L, int R) {
        return range_query_recur(0, 0, range - 1, L, R);
    }

    void inc(int L, int R, T X) {
        incUpdate_recur(0,0,range-1,L,R,X);
    }

    void set(int L, int R, T X) {
        setUpdate_recur(0,0,range-1,L,R,X);
    }

private:

    void build_recur(vector<T>& v, int l, int r, int node_no) {
        if(l == r) {
            if(l < (int)v.size())
                tree[node_no].val = v[l];
            else tree[node_no].val = identity;
            return;
        }
        int mid = (l+r)/2;
        build_recur(v, l, mid, 2*node_no + 1);
        build_recur(v, mid + 1, r, 2*node_no + 2);
        tree[node_no].val = f(tree[2*node_no + 1].val , tree[2*node_no + 2].val);
    }

    void incUpdate_recur(int node, int l, int r, int& L, int& R, T& X) {
        if(r < L || R < l || l >= range)
            return;
        if(L <= l && R >= r) {
            tree[node].increment += X;
            return;
        }
        applyAggr(node,l,r);
        int mid = (l+r)/2;
        incUpdate_recur(2*node+1,l,mid,L,R,X);
        incUpdate_recur(2*node+2,mid+1,r,L,R,X);
        applyAggr(2*node+1, l, mid);
        applyAggr(2*node+2, mid+1, r);
        tree[node].val = f(tree[2*node+1].val , tree[2*node+2].val);
    }
 
    void setUpdate_recur(int node, int l, int r, int& L, int& R, T& X) {
        if(r < L || R < l || l >= range)
            return;
        if(L <= l && R >= r) {
            tree[node].setAintValid = 1;
            tree[node].setAint = X;
            tree[node].increment = 0;
            return;
        }
        applyAggr(node,l,r);
        int mid = (l+r)/2;
        setUpdate_recur(2*node+1,l,mid,L,R,X);
        setUpdate_recur(2*node+2,mid+1,r,L,R,X);
        applyAggr(2*node+1, l, mid);
        applyAggr(2*node+2, mid+1, r);
        tree[node].val = f(tree[2*node+1].val , tree[2*node+2].val);
    }
 
    void compose(int par, int child) {
        if(tree[par].setAintValid){
            tree[child].setAintValid = 1;
            tree[child].setAint = tree[par].setAint;
            tree[child].increment = tree[par].increment;
        }
        else tree[child].increment += tree[par].increment;
    }
 
    void applyAggr(int node, int l, int r) {
        if(tree[node].setAintValid)
            tree[node].val = (r-l+1)*tree[node].setAint; //* remove range multiplication in min/max queries
        tree[node].val += (r-l+1)*tree[node].increment; //* remove range multiplication in min/max queries
        if(l != r){
            compose(node, 2*node + 1);
            compose(node, 2*node + 2);
        }
        tree[node].reset();
    }
 
    T range_query_recur(int node, int l, int r, int& L, int& R) {
        if(r < L || R < l || l >= range)
            return identity;
        applyAggr(node, l, r);
        if(L <= l && R >= r)
            return tree[node].val;
        int mid = (l+r)/2;
        return f(range_query_recur(2*node + 1, l, mid, L, R) , range_query_recur(2*node + 2, mid+1, r, L, R));
    }
};