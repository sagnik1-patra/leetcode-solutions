class Solution {
public:
    int solve(vector<int>& arr, int k) {
        int m = arr.size();
        
        vector<vector<int>> dp(m + 1, vector<int>(k + 1, 0));
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= k; j++) {
                dp[i][j] = dp[i - 1][j];
                
                int take = arr[i - 1];
                if (i > 1) take += dp[i - 2][j - 1];
                
                dp[i][j] = max(dp[i][j], take);
            }
        }
        
        return dp[m][k];
    }
    
    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size();
        int k = n / 3;
        
        // Case 1: exclude last
        vector<int> case1(slices.begin(), slices.end() - 1);
        
        // Case 2: exclude first
        vector<int> case2(slices.begin() + 1, slices.end());
        
        return max(solve(case1, k), solve(case2, k));
    }
};