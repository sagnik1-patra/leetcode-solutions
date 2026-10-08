
class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        set<int, greater<int>> sums;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                // Rhombus of size 0
                sums.insert(grid[i][j]);

                // Try all possible rhombus sizes
                for (int k = 1; i + 2 * k < m &&
                                    j - k >= 0 &&
                                    j + k < n; k++) {

                    int sum = 0;

                    // Top to right
                    for (int t = 0; t < k; t++)
                        sum += grid[i + t][j + t];

                    // Right to bottom
                    for (int t = 0; t < k; t++)
                        sum += grid[i + k + t][j + k - t];

                    // Bottom to left
                    for (int t = 0; t < k; t++)
                        sum += grid[i + 2*k - t][j - t];

                    // Left to top
                    for (int t = 0; t < k; t++)
                        sum += grid[i + k - t][j - k + t];

                    sums.insert(sum);
                }
            }
        }

        vector<int> ans;

        for (int x : sums) {
            ans.push_back(x);

            if (ans.size() == 3)
                break;
        }

        return ans;
    }
};
