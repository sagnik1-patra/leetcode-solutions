class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> answer(n, -1);

        for (int start = 0; start < n; start++) {
            int col = start;

            for (int row = 0; row < m; row++) {
                int nextCol = col + grid[row][col];

                // Hits left/right wall
                if (nextCol < 0 || nextCol >= n) {
                    col = -1;
                    break;
                }

                // V-shaped trap
                if (grid[row][col] != grid[row][nextCol]) {
                    col = -1;
                    break;
                }

                col = nextCol;
            }

            answer[start] = col;
        }

        return answer;
    }
};