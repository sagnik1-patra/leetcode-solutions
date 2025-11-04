class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1); // -1 = uncolored, 0 and 1 are two colors

        for (int i = 0; i < n; ++i) {
            if (color[i] == -1) {
                queue<int> q;
                q.push(i);
                color[i] = 0;

                while (!q.empty()) {
                    int node = q.front(); q.pop();
                    for (int nei : graph[node]) {
                        if (color[nei] == -1) {
                            color[nei] = 1 - color[node];
                            q.push(nei);
                        } else if (color[nei] == color[node]) {
                            return false; // same color conflict
                        }
                    }
                }
            }
        }

        return true;
    }
};
