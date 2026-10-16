
class Solution {
public:
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        const int MAX_SUM = 4900;

        vector<bool> dp(MAX_SUM + 1, false);
        dp[0] = true;

        for (auto& row : mat) {
            vector<bool> next(MAX_SUM + 1, false);

            for (int sum = 0; sum <= MAX_SUM; sum++) {
                if (dp[sum]) {
                    for (int x : row) {
                        if (sum + x <= MAX_SUM) {
                            next[sum + x] = true;
                        }
                    }
                }
            }

            dp = next;
        }

        int ans = INT_MAX;

        for (int sum = 0; sum <= MAX_SUM; sum++) {
            if (dp[sum]) {
                ans = min(ans, abs(target - sum));
            }
        }

        return ans;
    }
};
