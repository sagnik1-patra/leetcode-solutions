class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> result;
        vector<int> path;

        function<void(int)> dfs = [&](int node) {
            path.push_back(node);

            // If reached target node (n-1), record the path
            if (node == graph.size() - 1) {
                result.push_back(path);
            } else {
                // Explore all neighbors
                for (int next : graph[node]) {
                    dfs(next);
                }
            }

            path.pop_back(); // backtrack
        };

        dfs(0);
        return result;
    }
};