class Solution {
public:
    int catMouseGame(vector<vector<int>>& graph) {
        int n = graph.size();

        // 0 = draw, 1 = mouse win, 2 = cat win
        static int dp[50][50][2];
        static int degree[50][50][2];
        memset(dp, 0, sizeof(dp));

        queue<array<int,3>> q;

        // Initialize degrees correctly
        for (int m = 0; m < n; m++) {
            for (int c = 0; c < n; c++) {
                // Mouse turn: mouse can move anywhere
                degree[m][c][0] = graph[m].size();

                // Cat turn: cat cannot move to node 0
                degree[m][c][1] = 0;
                for (int x : graph[c]) {
                    if (x != 0) degree[m][c][1]++;
                }
            }
        }

        // Terminal states
        for (int i = 0; i < n; i++) {
            for (int t = 0; t < 2; t++) {
                if (i != 0) {
                    dp[0][i][t] = 1;  // mouse reaches hole
                    q.push({0, i, t});
                }
                dp[i][i][t] = 2;      // cat catches mouse
                q.push({i, i, t});
            }
        }

        // Retrograde BFS
        while (!q.empty()) {
            auto [m, c, t] = q.front(); q.pop();
            int res = dp[m][c][t];

            if (t == 0) {
                // Previous was cat's move
                for (int pc : graph[c]) {
                    if (pc == 0) continue;
                    if (dp[m][pc][1] != 0) continue;

                    if (res == 2) {
                        dp[m][pc][1] = 2;
                        q.push({m, pc, 1});
                    } else {
                        if (--degree[m][pc][1] == 0) {
                            dp[m][pc][1] = 1;
                            q.push({m, pc, 1});
                        }
                    }
                }
            } else {
                // Previous was mouse's move
                for (int pm : graph[m]) {
                    if (dp[pm][c][0] != 0) continue;

                    if (res == 1) {
                        dp[pm][c][0] = 1;
                        q.push({pm, c, 0});
                    } else {
                        if (--degree[pm][c][0] == 0) {
                            dp[pm][c][0] = 2;
                            q.push({pm, c, 0});
                        }
                    }
                }
            }
        }

        return dp[1][2][0];
    }
};
