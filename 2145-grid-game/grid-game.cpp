
class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();

        long long topSum = 0;
        long long bottomSum = 0;

        for (int i = 0; i < n; i++) {
            topSum += grid[0][i];
        }

        long long ans = LLONG_MAX;

        for (int i = 0; i < n; i++) {
            topSum -= grid[0][i];

            long long secondRobot = max(topSum, bottomSum);

            ans = min(ans, secondRobot);

            bottomSum += grid[1][i];
        }

        return ans;
    }
};
