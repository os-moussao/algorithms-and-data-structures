// Generated using Gemini 3 Pro
// Tested in: https://www.codechef.com/problems/XRQRS
struct PersistentTrie {
    static const int B = 31;
    
    // Memory pools
    vector<int> ch[2]; 
    vector<int> sz;
    vector<int> roots;
 
    PersistentTrie(int MX_UPDATES = 0) {
        if (MX_UPDATES) {
            // Reserve memory to prevent frequent reallocations
            ch[0].reserve(B * MX_UPDATES + 100); 
            ch[1].reserve(B * MX_UPDATES + 100);
            sz.reserve(B * MX_UPDATES + 100);
            roots.reserve(MX_UPDATES + 100);
        }
 
        // Create the "null" node at index 0.
        // Important: ch[0][0] = 0 and ch[1][0] = 0 implies null points to null.
        ch[0].push_back(0);
        ch[1].push_back(0);
        sz.push_back(0);
 
        // Version 0 is an empty trie rooted at null node (0)
        roots.push_back(0);
    }
 
    int get_latest_version() const {
        return roots.size() - 1;
    }
 
    int copy_node(int src) {
        int left = ch[0][src];
        int right = ch[1][src];
        int s = sz[src];
        
        ch[0].push_back(left);
        ch[1].push_back(right);
        sz.push_back(s);
        return sz.size() - 1;
    }

    int update(int prev_node, int val, int bit, int delta) {
        int cur = copy_node(prev_node);
        sz[cur] += delta;

        if (bit < 0) return cur;

        int b = (val >> bit) & 1;
        
        // Calculate the new child index FIRST.
        // If we did ch[b][cur] = update(...), the LHS reference could become invalid
        // if update() causes a vector resize.
        int child_node = update(ch[b][prev_node], val, bit - 1, delta);
        ch[b][cur] = child_node;
        
        return cur;
    }
 
    // Insert creates a NEW version based on version v
    int insert(int val, int v = -1) {
        if (v == -1) v = get_latest_version();
        int new_root = update(roots[v], val, B - 1, 1);
        roots.push_back(new_root);
        return roots.size() - 1;
    }
 
    // Erase creates a NEW version based on version v
    void erase(int val, int v = -1) {
        if (v == -1) v = get_latest_version();
        
        // If val doesn't exist, just duplicate the root to keep version indexing aligned
        if (query(val, 1, v) == 0) { 
            roots.push_back(roots[v]); 
            return;
        }
 
        int new_root = update(roots[v], val, B - 1, -1);
        roots.push_back(new_root);
    }
 
    // Count values in version 'v' such that (val ^ x) < k
    int query(int x, int k, int v) {
        int cur = roots[v];
        int ans = 0;
        for (int i = B - 1; i >= 0; i--) {
            if (cur == 0 || sz[cur] == 0) break;
            
            int b1 = (x >> i) & 1;
            int b2 = (k >> i) & 1;
            
            if (b2 == 1) {
                // k has bit 1.
                // 1. Same direction (b1): XOR is 0. 0 < 1. All valid.
                int same = ch[b1][cur];
                if (same) ans += sz[same];
                
                // 2. Opp direction (!b1): XOR is 1. 1 !< 1. Check deeper.
                cur = ch[!b1][cur];
            } else {
                // k has bit 0.
                // Must take path ensuring XOR bit is 0 (same direction b1).
                cur = ch[b1][cur];
            }
        }
        return ans;
    }

    // Returns maximum of val ^ x in version 'v'
    int get_max(int x, int v) {
        int cur = roots[v];
        if (cur == 0 || sz[cur] == 0) return 0;
        
        int ans = 0;
        for (int i = B - 1; i >= 0; i--) {
            int k = (x >> i) & 1;
            // Try opposite direction !k to maximize XOR
            int desired = ch[!k][cur];
            if (desired && sz[desired] > 0) {
                cur = desired;
                ans += (1 << i);
            } else {
                cur = ch[k][cur];
            }
        }
        return ans;
    }

    // Returns minimum of val ^ x in version 'v'
    int get_min(int x, int v) {
        int cur = roots[v];
        if (cur == 0 || sz[cur] == 0) return 0;
        
        int ans = 0;
        for (int i = B - 1; i >= 0; i--) {
            int k = (x >> i) & 1;
            // Try same direction k to minimize XOR
            int desired = ch[k][cur];
            if (desired && sz[desired] > 0) {
                cur = desired;
            } else {
                cur = ch[!k][cur];
                ans += (1 << i);
            }
        }
        return ans;
    }

    // Count values inserted between version vl and vr such that (val ^ x) < k
    int range_query(int vl, int vr, int x, int k) {
        int curL = (vl == -1) ? 0 : roots[vl];
        int curR = roots[vr];
        
        int ans = 0;
        for (int i = B - 1; i >= 0; i--) {
            int cntR = (curR == 0) ? 0 : sz[curR];
            int cntL = (curL == 0) ? 0 : sz[curL];
            if (cntR - cntL <= 0) break;
            
            int b1 = (x >> i) & 1;
            int b2 = (k >> i) & 1;
            
            if (b2 == 1) {
                int childL = (curL == 0) ? 0 : ch[b1][curL];
                int childR = (curR == 0) ? 0 : ch[b1][curR];
                
                int cR = childR ? sz[childR] : 0;
                int cL = childL ? sz[childL] : 0;
                ans += (cR - cL);
                
                curL = (curL == 0) ? 0 : ch[!b1][curL];
                curR = (curR == 0) ? 0 : ch[!b1][curR];
            } else {
                curL = (curL == 0) ? 0 : ch[b1][curL];
                curR = (curR == 0) ? 0 : ch[b1][curR];
            }
        }
        return ans;
    }

    // Get max XOR with x using values inserted between version vl and vr
    int get_range_max(int vl, int vr, int x) {
        int curL = (vl == -1) ? 0 : roots[vl]; 
        int curR = roots[vr];
        
        // Safety check if range is empty
        int totL = (curL == 0) ? 0 : sz[curL];
        int totR = (curR == 0) ? 0 : sz[curR];
        if (totR - totL <= 0) return 0; 

        int ans = 0;
        for (int i = B - 1; i >= 0; i--) {
            int k = (x >> i) & 1;
            
            // Try opposite direction !k
            int desiredL = (curL == 0) ? 0 : ch[!k][curL];
            int desiredR = (curR == 0) ? 0 : ch[!k][curR];
            
            int cR = desiredR ? sz[desiredR] : 0;
            int cL = desiredL ? sz[desiredL] : 0;

            if (cR - cL > 0) {
                curR = desiredR;
                curL = desiredL;
                ans |= (1 << i);
            } else {
                curL = (curL == 0) ? 0 : ch[k][curL];
                curR = (curR == 0) ? 0 : ch[k][curR];
            }
        }
        return ans;
    }

    // Get min XOR with x using values inserted between version vl and vr
    int get_range_min(int vl, int vr, int x) {
        int curL = (vl == -1) ? 0 : roots[vl]; 
        int curR = roots[vr];
        
        int totL = (curL == 0) ? 0 : sz[curL];
        int totR = (curR == 0) ? 0 : sz[curR];
        if (totR - totL <= 0) return 0; 

        int ans = 0;
        for (int i = B - 1; i >= 0; i--) {
            int k = (x >> i) & 1;
            
            // Try SAME direction k
            int desiredL = (curL == 0) ? 0 : ch[k][curL];
            int desiredR = (curR == 0) ? 0 : ch[k][curR];
            
            int cR = desiredR ? sz[desiredR] : 0;
            int cL = desiredL ? sz[desiredL] : 0;

            if (cR - cL > 0) {
                curR = desiredR;
                curL = desiredL;
            } else {
                curL = (curL == 0) ? 0 : ch[!k][curL];
                curR = (curR == 0) ? 0 : ch[!k][curR];
                ans |= (1 << i);
            }
        }
        return ans;
    }
};
