class Solution {
public:
    vector<int> ans;
    vector<int> quiet;
    vector<vector<int>> richerThan;
    
    int dfs(int x) {
        // If already computed, return
        if (ans[x] != -1) return ans[x];

        // Start by assuming the answer is the person x itself
        int best = x;

        // Explore all richer people
        for (int r : richerThan[x]) {
            int candidate = dfs(r);
            if (quiet[candidate] < quiet[best]) {
                best = candidate;
            }
        }

        return ans[x] = best;
    }

    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet_) {
        quiet = quiet_;
        int n = quiet.size();

        richerThan.assign(n, {});
        
        // Build reverse edges: if a is richer than b, store a in richerThan[b]
        for (auto &r : richer) {
            richerThan[r[1]].push_back(r[0]);
        }

        ans.assign(n, -1);

        // DFS for each person
        for (int i = 0; i < n; i++) {
            dfs(i);
        }

        return ans;
    }
};
