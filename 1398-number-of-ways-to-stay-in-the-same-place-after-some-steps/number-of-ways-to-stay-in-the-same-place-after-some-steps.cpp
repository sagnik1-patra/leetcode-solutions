class Solution {
public:
    int numWays(int steps, int arrLen) {
        const int MOD = 1e9 + 7;
        int n = min(arrLen, steps + 1); // no need to go beyond steps
        vector<int> dp(n, 0);
        dp[0] = 1;  // start at index 0

        for(int s = 1; s <= steps; s++) {
            vector<int> temp(n, 0);
            for(int i = 0; i < n; i++) {
                temp[i] = dp[i]; // stay
                if(i - 1 >= 0) temp[i] = (temp[i] + dp[i - 1]) % MOD; // left
                if(i + 1 < n) temp[i] = (temp[i] + dp[i + 1]) % MOD;   // right
            }
            dp = temp;
        }
        return dp[0];
    }
};