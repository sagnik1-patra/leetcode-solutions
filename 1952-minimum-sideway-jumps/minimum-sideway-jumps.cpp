class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        const int INF = 1e9;

        // Minimum side jumps to be in lanes 1, 2, 3
        // at point 0.
        vector<int> dp = {1, 0, 1};

        for (int i = 1; i < obstacles.size(); i++) {

            // First block the lane containing an obstacle.
            if (obstacles[i] != 0) {
                dp[obstacles[i] - 1] = INF;
            }

            // Best reachable lane at this point
            int best = min({dp[0], dp[1], dp[2]});

            // Try side-jumping into every available lane.
            for (int lane = 0; lane < 3; lane++) {
                if (obstacles[i] != lane + 1) {
                    dp[lane] = min(dp[lane], best + 1);
                }
            }
        }

        return min({dp[0], dp[1], dp[2]});
    }
};