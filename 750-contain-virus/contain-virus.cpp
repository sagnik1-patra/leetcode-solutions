class Solution {
public:
    int containVirus(vector<vector<int>>& isInfected) {
        int m = isInfected.size(), n = isInfected[0].size();
        int totalWalls = 0;
        vector<int> dirs = {1, 0, -1, 0, 1};

        while (true) {
            vector<vector<pair<int, int>>> regions;
            vector<unordered_set<int>> frontiers;
            vector<int> walls;

            vector<vector<int>> visited(m, vector<int>(n, 0));

            // Step 1: Identify infected regions and their frontiers
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (isInfected[i][j] == 1 && !visited[i][j]) {
                        vector<pair<int, int>> region;
                        unordered_set<int> frontier;
                        int wallCount = 0;

                        queue<pair<int, int>> q;
                        q.push({i, j});
                        visited[i][j] = 1;

                        while (!q.empty()) {
                            auto [x, y] = q.front();
                            q.pop();
                            region.push_back({x, y});

                            for (int d = 0; d < 4; ++d) {
                                int nx = x + dirs[d], ny = y + dirs[d + 1];
                                if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
                                if (isInfected[nx][ny] == 1 && !visited[nx][ny]) {
                                    visited[nx][ny] = 1;
                                    q.push({nx, ny});
                                } else if (isInfected[nx][ny] == 0) {
                                    wallCount++;
                                    frontier.insert(nx * n + ny);
                                }
                            }
                        }

                        regions.push_back(region);
                        frontiers.push_back(frontier);
                        walls.push_back(wallCount);
                    }
                }
            }

            if (regions.empty()) break;

            // Step 2: Find region with largest frontier (threat)
            int idx = max_element(frontiers.begin(), frontiers.end(),
                                  [](auto& a, auto& b) { return a.size() < b.size(); }) - frontiers.begin();

            if (frontiers[idx].empty()) break;

            totalWalls += walls[idx];

            // Step 3: Quarantine most dangerous region
            for (auto [x, y] : regions[idx]) isInfected[x][y] = -1;

            // Step 4: Spread virus from other regions
            for (int i = 0; i < regions.size(); ++i) {
                if (i == idx) continue;
                for (int cell : frontiers[i]) {
                    int x = cell / n, y = cell % n;
                    isInfected[x][y] = 1;
                }
            }
        }

        return totalWalls;
    }
};
