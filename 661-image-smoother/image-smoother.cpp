class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size(), n = img[0].size();
        vector<vector<int>> res(m, vector<int>(n, 0));

        // Directions for all 8 neighbors + itself
        vector<int> dirs = {-1, 0, 1};

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int sum = 0, count = 0;

                // Check all surrounding cells (3x3 grid)
                for (int dx : dirs) {
                    for (int dy : dirs) {
                        int x = i + dx, y = j + dy;
                        if (x >= 0 && x < m && y >= 0 && y < n) {
                            sum += img[x][y];
                            count++;
                        }
                    }
                }

                res[i][j] = sum / count; // floor division (integer division)
            }
        }

        return res;
    }
};
