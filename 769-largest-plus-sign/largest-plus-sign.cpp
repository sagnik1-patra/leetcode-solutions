class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> grid(n, vector<int>(n, n)); // initialize with n
        unordered_set<int> zeros;
        for (auto& m : mines) zeros.insert(m[0] * n + m[1]);

        // Pass 4 times (left→right, right→left, top→bottom, bottom→top)
        for (int i = 0; i < n; ++i) {
            int count = 0;
            // Left to right
            for (int j = 0; j < n; ++j) {
                count = zeros.count(i * n + j) ? 0 : count + 1;
                grid[i][j] = min(grid[i][j], count);
            }

            count = 0;
            // Right to left
            for (int j = n - 1; j >= 0; --j) {
                count = zeros.count(i * n + j) ? 0 : count + 1;
                grid[i][j] = min(grid[i][j], count);
            }
        }

        for (int j = 0; j < n; ++j) {
            int count = 0;
            // Top to bottom
            for (int i = 0; i < n; ++i) {
                count = zeros.count(i * n + j) ? 0 : count + 1;
                grid[i][j] = min(grid[i][j], count);
            }

            count = 0;
            // Bottom to top
            for (int i = n - 1; i >= 0; --i) {
                count = zeros.count(i * n + j) ? 0 : count + 1;
                grid[i][j] = min(grid[i][j], count);
            }
        }

        int ans = 0;
        for (auto& row : grid)
            for (int v : row)
                ans = max(ans, v);

        return ans;
    }
};
