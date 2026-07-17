class Solution {
public:
    vector<int> ans;
    vector<vector<int>> adj;
    string labels;
    
    vector<int> dfs(int node, int parent) {
        vector<int> freq(26, 0);
        
        // process children
        for (int nei : adj[node]) {
            if (nei == parent) continue;
            
            vector<int> childFreq = dfs(nei, node);
            
            // merge
            for (int i = 0; i < 26; i++) {
                freq[i] += childFreq[i];
            }
        }
        
        // include current node
        int idx = labels[node] - 'a';
        freq[idx]++;
        
        // store answer
        ans[node] = freq[idx];
        
        return freq;
    }
    
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        this->labels = labels;
        
        adj.resize(n);
        ans.resize(n);
        
        // build graph
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        dfs(0, -1);
        
        return ans;
    }
};