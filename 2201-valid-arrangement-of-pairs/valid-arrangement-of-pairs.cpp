class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, vector<int>> adj;
        unordered_map<int, int> indegree, outdegree;

        // Build graph
        for (auto& p : pairs) {
            int u = p[0];
            int v = p[1];

            adj[u].push_back(v);

            outdegree[u]++;
            indegree[v]++;
        }

        // Find starting node
        int start = pairs[0][0];

        for (auto& p : pairs) {
            int u = p[0];

            if (outdegree[u] - indegree[u] == 1) {
                start = u;
                break;
            }
        }

        // Hierholzer's Algorithm
        stack<int> st;
        vector<int> path;

        st.push(start);

        while (!st.empty()) {
            int u = st.top();

            if (!adj[u].empty()) {
                int v = adj[u].back();
                adj[u].pop_back();

                st.push(v);
            }
            else {
                path.push_back(u);
                st.pop();
            }
        }

        reverse(path.begin(), path.end());

        vector<vector<int>> ans;

        for (int i = 0; i + 1 < path.size(); i++) {
            ans.push_back({path[i], path[i + 1]});
        }

        return ans;
    }
};