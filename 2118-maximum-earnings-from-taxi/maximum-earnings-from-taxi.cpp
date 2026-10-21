
class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {

        vector<vector<pair<int, int>>> ending(n + 1);

        for (auto& ride : rides) {
            int start = ride[0];
            int end = ride[1];
            int tip = ride[2];

            ending[end].push_back({start, end - start + tip});
        }

        vector<long long> dp(n + 1, 0);

        for (int i = 1; i <= n; i++) {

            dp[i] = dp[i - 1];

            for (auto& ride : ending[i]) {
                int start = ride.first;
                int profit = ride.second;

                dp[i] = max(dp[i], dp[start] + profit);
            }
        }

        return dp[n];
    }
};
