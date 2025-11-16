class Solution {
public:
    int n;
    vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
    
    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size();
        int index = 2;  // start labeling islands from 2
        unordered_map<int, int> area;  // island id -> area size

        // 1️⃣ Label each island uniquely and store its area
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    area[index] = dfs(grid, i, j, index);
                    index++;
                }
            }
        }

        // 2️⃣ If all are 1’s, return total area
        int maxArea = 0;
        for (auto &a : area) maxArea = max(maxArea, a.second);
        if (maxArea == n * n) return maxArea;

        // 3️⃣ Try flipping each 0 → 1 and calculate connected island area
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    unordered_set<int> seen;
                    int newArea = 1;
                    for (auto &d : dirs) {
                        int r = i + d[0], c = j + d[1];
                        if (r >= 0 && c >= 0 && r < n && c < n && grid[r][c] > 1 && !seen.count(grid[r][c])) {
                            newArea += area[grid[r][c]];
                            seen.insert(grid[r][c]);
                        }
                    }
                    maxArea = max(maxArea, newArea);
                }
            }
        }

        return maxArea;
    }

    // DFS to calculate area and label island
    int dfs(vector<vector<int>>& grid, int i, int j, int id) {
        if (i < 0 || j < 0 || i >= n || j >= n || grid[i][j] != 1) return 0;
        grid[i][j] = id;
        int res = 1;
        for (auto &d : dirs) res += dfs(grid, i + d[0], j + d[1], id);
        return res;
    }
};