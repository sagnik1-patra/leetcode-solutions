class Solution {
public:
    string largestNumber(vector<int>& cost, int target) {
        vector<int> dp(target + 1, INT_MIN);
        dp[0] = 0;
        
        // Step 1: DP for max digits
        for (int t = 1; t <= target; t++) {
            for (int d = 0; d < 9; d++) {
                if (t >= cost[d] && dp[t - cost[d]] != INT_MIN) {
                    dp[t] = max(dp[t], dp[t - cost[d]] + 1);
                }
            }
        }
        
        if (dp[target] < 0) return "0";
        
        // Step 2: reconstruct
        string result = "";
        int t = target;
        
        for (int d = 8; d >= 0; d--) { // digits 9 → 1
            while (t >= cost[d] && dp[t] == dp[t - cost[d]] + 1) {
                result += (d + '1');
                t -= cost[d];
            }
        }
        
        return result;
    }
};