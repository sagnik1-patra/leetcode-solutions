class Solution {
public:
    vector<int> parent;
    
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    
    void unite(int x, int y) {
        parent[find(x)] = find(y);
    }
    
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        parent.resize(n + 1);
        
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
        
        // Connect multiples
        for (int d = threshold + 1; d <= n; d++) {
            for (int multiple = 2 * d; multiple <= n; multiple += d) {
                unite(d, multiple);
            }
        }
        
        vector<bool> ans;
        
        for (auto &q : queries) {
            int a = q[0], b = q[1];
            ans.push_back(find(a) == find(b));
        }
        
        return ans;
    }
};