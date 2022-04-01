// problem: https://leetcode.com/problems/longest-consecutive-sequence/

class DSU {
public:
	int N = 0;
	int cnt = 0;
	vector <int> par;
	vector <int> sz;
	vector <int> rnk;
	DSU(){N=0; cnt=0;}
	DSU(int n) {
		N = cnt = n;
		par.resize(n);  sz.resize(n);  rnk.resize(n);
		for (int i = 0; i < n; i++) {
			par[i] = i; sz[i] = 1; rnk[i] = 0;
		}
	}
	int find(int p) {
		return (p == par[p]? p: par[p] = find(par[p]));
	}
	bool connected(int p, int q) {
		return find(p) == find(q);
	}
	int size(int p) {
		return sz[find(p)];
	}
	bool unify(int p, int q)
	{
		int root1 = find(p);
		int root2 = find(q);
		if (root1 == root2) return 0;
		if (rnk[root2] > rnk[root1]) swap(root1, root2);
		par[root2] = root1;
		sz[root1] += sz[root2];
		if (rnk[root1] == rnk[root2])  rnk[root1]++;
		cnt--;
		return 1;
	}
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map <int, int> index;
        map <int, bool> exist;
        int x;
        DSU dsu(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            x = nums[i];
            if (!exist[x]) {
                index[x] = i;
                exist[x] = 1;
                if (exist[x + 1]) dsu.unify(i, index[x + 1]);
                if (exist[x - 1]) dsu.unify(i, index[x - 1]);
            }
        }
        int mx = 0;
        for (int i = 0; i < nums.size(); i++) {
            mx = max(mx, dsu.size(i));
        }
        return mx;
    }
};