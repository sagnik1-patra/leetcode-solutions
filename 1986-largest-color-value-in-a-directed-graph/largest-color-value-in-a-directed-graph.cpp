class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();

        vector<vector<int>> graph(n);
        vector<int> indegree(n, 0);

        // Build graph
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            graph[u].push_back(v);
            indegree[v]++;
        }

        // dp[i][c] = maximum number of color c
        // on any path ending at node i
        vector<vector<int>> dp(n, vector<int>(26, 0));

        queue<int> q;

        // Add all nodes with indegree 0
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int processed = 0;
        int answer = 0;

        while (!q.empty()) {

            int u = q.front();
            q.pop();

            processed++;

            int color = colors[u] - 'a';

            // Include current node's color
            dp[u][color]++;

            answer = max(answer, dp[u][color]);

            // Send DP information to neighbors
            for (int v : graph[u]) {

                for (int c = 0; c < 26; c++) {
                    dp[v][c] = max(dp[v][c], dp[u][c]);
                }

                indegree[v]--;

                if (indegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        // If not all nodes were processed, graph has a cycle
        if (processed != n) {
            return -1;
        }

        return answer;
    }
};