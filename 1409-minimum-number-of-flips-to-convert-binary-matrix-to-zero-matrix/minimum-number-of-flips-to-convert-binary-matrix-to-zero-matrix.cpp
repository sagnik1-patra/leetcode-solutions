class Solution {
public:
    int minFlips(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();

        // Convert matrix to bitmask
        int start = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1) {
                    start |= (1 << (i * n + j));
                }
            }
        }

        // BFS
        queue<pair<int,int>> q; // {state, steps}
        unordered_set<int> visited;

        q.push({start, 0});
        visited.insert(start);

        // Directions (self + 4 neighbors)
        vector<int> dirs = {0, 1, 0, -1, 0};

        while (!q.empty()) {
            auto [state, steps] = q.front();
            q.pop();

            // If zero matrix
            if (state == 0) return steps;

            // Try flipping each cell
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    int next = state;

                    // Flip (i,j) and neighbors
                    for (int d = 0; d < 4; d++) {
                        int ni = i + dirs[d];
                        int nj = j + dirs[d+1];

                        if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
                            next ^= (1 << (ni * n + nj));
                        }
                    }
                    // Flip itself
                    next ^= (1 << (i * n + j));

                    if (!visited.count(next)) {
                        visited.insert(next);
                        q.push({next, steps + 1});
                    }
                }
            }
        }

        return -1;
    }
};