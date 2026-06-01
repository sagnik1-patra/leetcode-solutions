class Solution {
public:
    int maxStudents(vector<vector<char>>& seats) {
        int m = seats.size();
        int n = seats[0].size();
        
        vector<vector<int>> validMasks(m);
        
        // Step 1: generate valid masks for each row
        for (int i = 0; i < m; i++) {
            for (int mask = 0; mask < (1 << n); mask++) {
                
                bool ok = true;
                
                // check adjacent in same row
                if (mask & (mask << 1)) ok = false;
                
                for (int j = 0; j < n; j++) {
                    if ((mask & (1 << j)) && seats[i][j] == '#') {
                        ok = false;
                    }
                }
                
                if (ok) validMasks[i].push_back(mask);
            }
        }
        
        // Step 2: DP
        vector<vector<int>> dp(m, vector<int>(1 << n, 0));
        
        // first row
        for (int mask : validMasks[0]) {
            dp[0][mask] = __builtin_popcount(mask);
        }
        
        // remaining rows
        for (int i = 1; i < m; i++) {
            for (int curr : validMasks[i]) {
                int currCount = __builtin_popcount(curr);
                
                for (int prev : validMasks[i - 1]) {
                    
                    // check cheating diagonals
                    if ((curr & (prev << 1)) == 0 &&
                        (curr & (prev >> 1)) == 0) {
                        
                        dp[i][curr] = max(dp[i][curr], 
                                          dp[i - 1][prev] + currCount);
                    }
                }
            }
        }
        
        // Step 3: result
        int ans = 0;
        for (int mask : validMasks[m - 1]) {
            ans = max(ans, dp[m - 1][mask]);
        }
        
        return ans;
    }
};