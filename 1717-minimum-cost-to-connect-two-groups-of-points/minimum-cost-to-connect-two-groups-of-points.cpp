class Solution {
public:
    int connectTwoGroups(vector<vector<int>>& cost) {
        int m = cost.size(), n = cost[0].size();
        int MAX = 1e9;
        
        // min cost to connect each group2 node
        vector<int> minCost(n, MAX);
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < m; i++) {
                minCost[j] = min(minCost[j], cost[i][j]);
            }
        }
        
        int FULL = (1 << n);
        vector<vector<int>> dp(m + 1, vector<int>(FULL, MAX));
        dp[0][0] = 0;
        
        for (int i = 0; i < m; i++) {
            for (int mask = 0; mask < FULL; mask++) {
                if (dp[i][mask] == MAX) continue;
                
                for (int j = 0; j < n; j++) {
                    int newMask = mask | (1 << j);
                    dp[i+1][newMask] = min(dp[i+1][newMask],
                                           dp[i][mask] + cost[i][j]);
                }
            }
        }
        
        int ans = MAX;
        
        // finalize by covering remaining nodes
        for (int mask = 0; mask < FULL; mask++) {
            int extra = 0;
            for (int j = 0; j < n; j++) {
                if (!(mask & (1 << j))) {
                    extra += minCost[j];
                }
            }
            ans = min(ans, dp[m][mask] + extra);
        }
        
        return ans;
    }
};