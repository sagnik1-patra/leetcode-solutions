
class Solution {
public:
    int minSkips(vector<int>& dist, int speed,
                 int hoursBefore) {

        int n = dist.size();
        long long INF = 1e18;

        vector<long long> dp(n + 1, INF);
        dp[0] = 0;

        for (int i = 0; i < n; i++) {
            vector<long long> next(n + 1, INF);

            for (int j = 0; j <= i; j++) {
                if (dp[j] == INF)
                    continue;

                long long time = dp[j] + dist[i];

                // Skip the rest
                next[j + 1] = min(next[j + 1], time);

                // Do not skip the rest
                if (i == n - 1) {
                    next[j] = min(next[j], time);
                } else {
                    long long rounded =
                        ((time + speed - 1) / speed) * speed;

                    next[j] = min(next[j], rounded);
                }
            }

            dp = next;
        }

        long long limit = 1LL * hoursBefore * speed;

        for (int j = 0; j <= n; j++) {
            if (dp[j] <= limit)
                return j;
        }

        return -1;
    }
};
