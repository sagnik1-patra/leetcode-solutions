class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> result;
        result.reserve(rows * cols);

        // Directions: East, South, West, North
        int dr[4] = {0, 1, 0, -1};
        int dc[4] = {1, 0, -1, 0};

        int r = rStart, c = cStart;
        result.push_back({r, c});

        int steps = 1;
        int dir = 0;

        while (result.size() < rows * cols) {
            // Each step size is repeated twice
            for (int rep = 0; rep < 2; rep++) {
                for (int i = 0; i < steps; i++) {
                    r += dr[dir];
                    c += dc[dir];

                    if (r >= 0 && r < rows && c >= 0 && c < cols) {
                        result.push_back({r, c});
                    }
                }
                dir = (dir + 1) % 4;
            }
            steps++;
        }

        return result;
    }
};
