class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();

        vector<bool> dp(n, false);
        dp[0] = true;

        int reachable = 0;

        for (int i = 1; i < n; i++) {

            // Add dp[i - minJump] to the window
            if (i - minJump >= 0 && dp[i - minJump]) {
                reachable++;
            }

            // Remove dp[i - maxJump - 1] from the window
            if (i - maxJump - 1 >= 0 &&
                dp[i - maxJump - 1]) {
                reachable--;
            }

            // i is reachable if:
            // 1. s[i] is '0'
            // 2. At least one reachable previous position
            //    exists in the valid jump range
            if (s[i] == '0' && reachable > 0) {
                dp[i] = true;
            }
        }

        return dp[n - 1];
    }
};