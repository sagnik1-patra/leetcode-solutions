class Solution {
public:
    vector<int> shortestAlternatingPaths(int n,
                                         vector<vector<int>>& redEdges,
                                         vector<vector<int>>& blueEdges) {
        vector<vector<int>> redAdj(n), blueAdj(n);

        // Build adjacency lists
        for (auto &e : redEdges)
            redAdj[e[0]].push_back(e[1]);

        for (auto &e : blueEdges)
            blueAdj[e[0]].push_back(e[1]);

        // dist[node][color] : shortest distance to node ending with color
        // color: 0 = red, 1 = blue
        vector<vector<int>> dist(n, vector<int>(2, -1));

        queue<pair<int,int>> q;

        // Start from node 0 with both colors
        q.push({0, 0});
        q.push({0, 1});
        dist[0][0] = dist[0][1] = 0;

        while (!q.empty()) {
            auto [node, color] = q.front();
            q.pop();

            if (color == 0) {
                // Last was red → use blue edges
                for (int next : blueAdj[node]) {
                    if (dist[next][1] == -1) {
                        dist[next][1] = dist[node][0] + 1;
                        q.push({next, 1});
                    }
                }
            } else {
                // Last was blue → use red edges
                for (int next : redAdj[node]) {
                    if (dist[next][0] == -1) {
                        dist[next][0] = dist[node][1] + 1;
                        q.push({next, 0});
                    }
                }
            }
        }

        // Build answer
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            if (dist[i][0] == -1 && dist[i][1] == -1)
                ans[i] = -1;
            else if (dist[i][0] == -1)
                ans[i] = dist[i][1];
            else if (dist[i][1] == -1)
                ans[i] = dist[i][0];
            else
                ans[i] = min(dist[i][0], dist[i][1]);
        }

        return ans;
    }
};
