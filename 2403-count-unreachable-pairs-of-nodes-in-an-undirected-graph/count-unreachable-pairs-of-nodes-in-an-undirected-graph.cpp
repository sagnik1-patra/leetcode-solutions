class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adj(n);

        // Create adjacency list
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> visited(n, false);

        long long ans = 0;
        long long remaining = n;

        for (int i = 0; i < n; i++) {

            if (!visited[i]) {

                long long size = 0;
                queue<int> q;

                q.push(i);
                visited[i] = true;

                // Find connected component size
                while (!q.empty()) {

                    int node = q.front();
                    q.pop();

                    size++;

                    for (int neighbour : adj[node]) {

                        if (!visited[neighbour]) {
                            visited[neighbour] = true;
                            q.push(neighbour);
                        }
                    }
                }

                remaining -= size;
                ans += size * remaining;
            }
        }

        return ans;
    }
};