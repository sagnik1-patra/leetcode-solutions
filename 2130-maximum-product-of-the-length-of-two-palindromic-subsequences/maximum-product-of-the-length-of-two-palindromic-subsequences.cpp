
class Solution {
public:
    int maxProduct(string s) {
        int n = s.size();
        int total = 1 << n;

        vector<int> dp(total, 0);

        // Find all palindromic subsequences
        for (int mask = 1; mask < total; mask++) {
            string temp = "";

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    temp += s[i];
                }
            }

            string rev = temp;
            reverse(rev.begin(), rev.end());

            if (temp == rev) {
                dp[mask] = temp.size();
            }
        }

        int ans = 0;

        // Check pairs of disjoint subsequences
        for (int i = 1; i < total; i++) {
            if (dp[i] == 0)
                continue;

            for (int j = i + 1; j < total; j++) {
                if (dp[j] == 0)
                    continue;

                if ((i & j) == 0) {
                    ans = max(ans, dp[i] * dp[j]);
                }
            }
        }

        return ans;
    }
};
