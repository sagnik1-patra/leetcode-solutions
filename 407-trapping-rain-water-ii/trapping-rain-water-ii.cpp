class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        int n = heightMap[0].size();
        if (m < 3 || n < 3) return 0;

        using Cell = pair<int, pair<int,int>>; // (height, (i,j))
        priority_queue<Cell, vector<Cell>, greater<Cell>> pq;

        vector<vector<bool>> vis(m, vector<bool>(n, false));

        // Push all boundary cells
        for (int i = 0; i < m; ++i) {
            pushCell(i, 0, heightMap, vis, pq);
            pushCell(i, n-1, heightMap, vis, pq);
        }
        for (int j = 1; j < n-1; ++j) {
            pushCell(0, j, heightMap, vis, pq);
            pushCell(m-1, j, heightMap, vis, pq);
        }

        long long water = 0;
        const int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        while (!pq.empty()) {
            auto [h, pos] = pq.top(); pq.pop();
            int i = pos.first, j = pos.second;

            for (auto &d : dirs) {
                int ni = i + d[0], nj = j + d[1];
                if (ni < 0 || ni >= m || nj < 0 || nj >= n || vis[ni][nj]) continue;
                vis[ni][nj] = true;

                int nh = heightMap[ni][nj];
                if (nh < h) water += (long long)(h - nh);
                // Neighbor's effective height is max(nh, h)
                pq.push({max(nh, h), {ni, nj}});
            }
        }
        return (int)water;
    }

private:
    void pushCell(int i, int j,
                  const vector<vector<int>>& heightMap,
                  vector<vector<bool>>& vis,
                  priority_queue<pair<int,pair<int,int>>,
                                 vector<pair<int,pair<int,int>>>,
                                 greater<pair<int,pair<int,int>>>>& pq) {
        if (!vis[i][j]) {
            vis[i][j] = true;
            pq.push({heightMap[i][j], {i, j}});
        }
    }
};
