class Solution {
public:
    vector<vector<int>> adj;
    vector<int> subXor, tin, tout;
    int timer = 0;

    void dfs(int node, int parent, vector<int>& nums) {

        tin[node] = timer++;
        subXor[node] = nums[node];

        for (int child : adj[node]) {

            if (child == parent)
                continue;

            dfs(child, node, nums);

            subXor[node] ^= subXor[child];
        }

        tout[node] = timer++;
    }

    bool isAncestor(int u, int v) {
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }

    int minimumScore(vector<int>& nums,
                     vector<vector<int>>& edges) {

        int n = nums.size();

        adj.assign(n, {});
        subXor.resize(n);
        tin.resize(n);
        tout.resize(n);
        timer = 0;

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfs(0, -1, nums);

        int total = subXor[0];
        int ans = INT_MAX;

        for (int u = 1; u < n; u++) {
            for (int v = u + 1; v < n; v++) {

                int x, y, z;

                if (isAncestor(u, v)) {

                    x = subXor[v];
                    y = subXor[u] ^ subXor[v];
                    z = total ^ subXor[u];
                }
                else if (isAncestor(v, u)) {

                    x = subXor[u];
                    y = subXor[v] ^ subXor[u];
                    z = total ^ subXor[v];
                }
                else {

                    x = subXor[u];
                    y = subXor[v];
                    z = total ^ x ^ y;
                }

                int score = max({x, y, z}) -
                            min({x, y, z});

                ans = min(ans, score);

                if (ans == 0)
                    return 0;
            }
        }

        return ans;
    }
};