class Solution {
public:
    vector<vector<int>> graph;
    vector<int> ans;
    
    // For each value 1..50, store {depth, node}
    vector<pair<int, int>> closest;

    void dfs(int node, int parent, int depth, vector<int>& nums) {
        int value = nums[node];

        int bestDepth = -1;
        int bestNode = -1;

        // Find deepest ancestor whose value is coprime
        for (int v = 1; v <= 50; v++) {
            if (gcd(value, v) == 1 && closest[v].first > bestDepth) {
                bestDepth = closest[v].first;
                bestNode = closest[v].second;
            }
        }

        ans[node] = bestNode;

        // Save previous state
        pair<int, int> previous = closest[value];

        // Current node becomes closest node with this value
        closest[value] = {depth, node};

        for (int next : graph[node]) {
            if (next != parent) {
                dfs(next, node, depth + 1, nums);
            }
        }

        // Restore when backtracking
        closest[value] = previous;
    }

    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();

        graph.assign(n, {});

        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        ans.assign(n, -1);
        closest.assign(51, {-1, -1});

        dfs(0, -1, 0, nums);

        return ans;
    }
};