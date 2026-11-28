class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        map<vector<int>, int> mp;
        int ans = 0;

        // Store all rows with their frequencies
        for (int i = 0; i < n; i++) {
            mp[grid[i]]++;
        }

        // Construct each column
        for (int j = 0; j < n; j++) {
            vector<int> col;

            for (int i = 0; i < n; i++) {
                col.push_back(grid[i][j]);
            }

            // Count matching rows
            if (mp.count(col)) {
                ans += mp[col];
            }
        }

        return ans;
    }
};