// Generated using Gemini 3 Pro
struct PersistentTrie {
    static const int B = 31;
    
    // Memory pools: use integers instead of pointers
    // ch[0] stores '0' bit children, ch[1] stores '1' bit children
    // sz stores subtree size
    // Using simple vectors acts as a fast memory pool
    vector<int> ch[2]; 
    vector<int> sz;
    
    // Stores the root index for each version
    vector<int> roots;
 
    PersistentTrie(int MX_UPDATES) {
        // Reserve memory to prevent reallocations during runtime if N is large.
        // E.g., if you have 200k queries, ~6 million nodes might be needed.
        ch[0].reserve(B * MX_UPDATES + 100); 
        ch[1].reserve(B * MX_UPDATES + 100);
        sz.reserve(B * MX_UPDATES + 100);
        roots.reserve(MX_UPDATES + 100);
 
        // Create the "null" node at index 0
        ch[0].push_back(0);
        ch[1].push_back(0);
        sz.push_back(0);
 
        // Version 0 is an empty trie rooted at null node (0)
        roots.push_back(0);
    }
 
    int get_latest_version() const {
        return roots.size() - 1;
    }
 
    // Helper: Creates a clone of node 'src' and returns the new index
    int copy_node(int src) {
        ch[0].push_back(ch[0][src]);
        ch[1].push_back(ch[1][src]);
        sz.push_back(sz[src]);
        return sz.size() - 1;
    }
 
    // Internal update function
    int update(int prev_node, int val, int bit, int delta) {
        int cur = copy_node(prev_node);
        sz[cur] += delta;

        if (bit < 0) return cur;

        int b = (val >> bit) & 1;
        // The child we are modifying updates to a new node
        // The other child remains pointing to the same index (structural sharing)
        ch[b][cur] = update(ch[b][prev_node], val, bit - 1, delta);
        
        return cur;
    }
 
    // Insert creates a NEW version
    int insert(int val, int v = -1) {
        if (v == -1) v = get_latest_version();
        int new_root = update(roots[v], val, B - 1, 1);
        roots.push_back(new_root);
        return roots.size() - 1;
    }
 
    // Erase creates a NEW version
    void erase(int val, int v = -1) {
        if (v == -1) v = get_latest_version();
        
        // Optimization: If val doesn't exist, just duplicate the root
        // so version numbers stay consistent
        if (query(val, 1, v) == 0) { 
            roots.push_back(roots[v]); 
            return;
        }
 
        int new_root = update(roots[v], val, B - 1, -1);
        roots.push_back(new_root);
    }
 
    // Query: count values in version 'v' such that (val ^ x) < k
    // To count occurrences of x: use query(x, 1, v)
    int query(int x, int k, int v) {
        int cur = roots[v];
        int ans = 0;
        for (int i = B - 1; i >= 0; i--) {
            // Index 0 is the null node, sz[0] is always 0
            if (cur == 0 || sz[cur] == 0) break;
            
            int b1 = (x >> i) & 1;
            int b2 = (k >> i) & 1;
            
            if (b2 == 1) {
                // If k has bit 1, the path matching x (b1) results in XOR bit 0.
                // Since 0 < 1, all these numbers are valid.
                int child_matching_x = ch[b1][cur];
                if (child_matching_x) ans += sz[child_matching_x];
                
                // Then we descend into the OTHER side (!b1) where XOR bit is 1.
                // Since 1 == 1, we need to check lower bits.
                cur = ch[!b1][cur];
            } else {
                // If k has bit 0, we MUST take path that produces bit 0 in XOR.
                // This means we must follow b1.
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
};
