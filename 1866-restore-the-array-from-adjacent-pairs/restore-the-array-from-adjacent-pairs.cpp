class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> graph;

        // Build adjacency list
        for (auto& pair : adjacentPairs) {
            int u = pair[0];
            int v = pair[1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        // Find an endpoint (degree = 1)
        int start = 0;

        for (auto& entry : graph) {
            if (entry.second.size() == 1) {
                start = entry.first;
                break;
            }
        }

        int n = adjacentPairs.size() + 1;
        vector<int> nums;
        nums.reserve(n);

        int previous = INT_MAX;
        int current = start;

        while (nums.size() < n) {
            nums.push_back(current);

            int next = INT_MAX;

            for (int neighbor : graph[current]) {
                if (neighbor != previous) {
                    next = neighbor;
                    break;
                }
            }

            previous = current;
            current = next;
        }

        return nums;
    }
};