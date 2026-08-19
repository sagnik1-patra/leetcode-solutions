class Solution {
public:
    int countVowelStrings(int n) {
        vector<int> dp(5, 1);

        for (int len = 2; len <= n; len++) {
            for (int j = 1; j < 5; j++) {
                dp[j] += dp[j - 1];
            }
        }

        int ans = 0;

        for (int x : dp) {
            ans += x;
        }

        return ans;
    }
};