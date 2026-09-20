class Solution {
public:
    int checkWays(vector<vector<int>>& pairs) {
        unordered_map<int, unordered_set<int>> graph;

        // Build undirected graph
        for (auto& p : pairs) {
            graph[p[0]].insert(p[1]);
            graph[p[1]].insert(p[0]);
        }

        int n = graph.size();

        // Find root: it must be connected to every other node
        int root = -1;

        for (auto& [node, neighbors] : graph) {
            if (neighbors.size() == n - 1) {
                root = node;
                break;
            }
        }

        // No valid root
        if (root == -1) {
            return 0;
        }

        int result = 1;

        for (auto& [node, neighbors] : graph) {
            if (node == root) {
                continue;
            }

            int parent = -1;
            int parentDegree = INT_MAX;
            int nodeDegree = neighbors.size();

            // Find parent:
            // parent must be a neighbor with degree >= node's degree
            // Choose the one with smallest possible degree
            for (int neighbor : neighbors) {
                int degree = graph[neighbor].size();

                if (degree >= nodeDegree && degree < parentDegree) {
                    parent = neighbor;
                    parentDegree = degree;
                }
            }

            // No possible parent
            if (parent == -1) {
                return 0;
            }

            // Every neighbor of node, except parent,
            // must also be connected to parent
            for (int neighbor : neighbors) {
                if (neighbor == parent) {
                    continue;
                }

                if (!graph[parent].count(neighbor)) {
                    return 0;
                }
            }

            // Same degree means parent/child relation can be swapped,
            // so multiple valid trees exist
            if (parentDegree == nodeDegree) {
                result = 2;
            }
        }

        return result;
    }
};