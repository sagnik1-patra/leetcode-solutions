class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>> graph(n);

        for (auto &edge : connections) {
            int a = edge[0];
            int b = edge[1];

            graph[a].push_back({b, 1}); // original direction, needs reversal
            graph[b].push_back({a, 0}); // reverse direction, already good
        }

        vector<bool> visited(n, false);
        queue<int> q;
        q.push(0);
        visited[0] = true;

        int count = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto &[next, cost] : graph[node]) {
                if (!visited[next]) {
                    visited[next] = true;
                    count += cost;
                    q.push(next);
                }
            }
        }

        return count;
    }
};