
class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj,
             vector<bool>& visited) {

        for (int next : adj[node]) {
            if (!visited[next]) {
                visited[next] = true;
                dfs(next, adj, visited);
            }
        }
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<vector<int>> ans(n);

        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
        }

        for (int i = 0; i < n; i++) {
            vector<bool> visited(n, false);

            dfs(i, adj, visited);

            for (int j = 0; j < n; j++) {
                if (visited[j]) {
                    ans[j].push_back(i);
                }
            }
        }

        return ans;
    }
};
