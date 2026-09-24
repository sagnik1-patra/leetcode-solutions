class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        vector<vector<bool>> graph(n + 1, vector<bool>(n + 1, false));
        vector<int> degree(n + 1, 0);

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            graph[u][v] = true;
            graph[v][u] = true;

            degree[u]++;
            degree[v]++;
        }

        int answer = INT_MAX;

        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (!graph[i][j]) continue;

                for (int k = j + 1; k <= n; k++) {
                    if (graph[i][k] && graph[j][k]) {
                        int trioDegree =
                            degree[i] + degree[j] + degree[k] - 6;

                        answer = min(answer, trioDegree);
                    }
                }
            }
        }

        return answer == INT_MAX ? -1 : answer;
    }
};