
class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        vector<int> dp(k + 1, 0);

        for (auto& pile : piles) {

            int n = pile.size();

            // Calculate prefix sums
            vector<int> prefix(n + 1, 0);

            for (int i = 0; i < n; i++) {
                prefix[i + 1] = prefix[i] + pile[i];
            }

            // Process current pile
            for (int j = k; j >= 1; j--) {

                for (int x = 1; x <= min(j, n); x++) {

                    dp[j] = max(dp[j],
                                dp[j - x] + prefix[x]);
                }
            }
        }

        return dp[k];
    }
};
