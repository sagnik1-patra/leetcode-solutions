class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> reverseGraph(n);
        vector<int> indegree(n, 0);

        // Step 1: Reverse the graph edges
        for (int i = 0; i < n; i++) {
            for (int j : graph[i]) {
                reverseGraph[j].push_back(i);
                indegree[i]++;
            }
        }

        // Step 2: Perform topological sort (Kahn's algorithm)
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0)
                q.push(i); // terminal nodes
        }

        vector<int> safe;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safe.push_back(node);

            for (int nei : reverseGraph[node]) {
                indegree[nei]--;
                if (indegree[nei] == 0)
                    q.push(nei);
            }
        }

        sort(safe.begin(), safe.end());
        return safe;
    }
};
