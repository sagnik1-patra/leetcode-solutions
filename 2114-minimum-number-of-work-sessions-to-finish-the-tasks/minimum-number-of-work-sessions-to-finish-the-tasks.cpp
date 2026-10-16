
class Solution {
public:
    int minSessions(vector<int>& tasks, int sessionTime) {
        int n = tasks.size();
        int total = 1 << n;

        vector<pair<int, int>> dp(total, {n + 1, 0});

        dp[0] = {1, 0};

        for (int mask = 0; mask < total; mask++) {
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    continue;
                }

                int newMask = mask | (1 << i);

                int sessions = dp[mask].first;
                int usedTime = dp[mask].second;

                if (usedTime + tasks[i] <= sessionTime) {
                    usedTime += tasks[i];
                } else {
                    sessions++;
                    usedTime = tasks[i];
                }

                dp[newMask] = min(
                    dp[newMask],
                    make_pair(sessions, usedTime)
                );
            }
        }

        return dp[total - 1].first;
    }
};
