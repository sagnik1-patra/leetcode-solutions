class Solution {
public:
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();

        vector<vector<int>> adj(n);

        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        int ans = 1;

        function<int(int)> dfs = [&](int node) {
            int longest = 0;
            int secondLongest = 0;

            for (int child : adj[node]) {
                int len = dfs(child);

                if (s[node] == s[child])
                    continue;

                if (len > longest) {
                    secondLongest = longest;
                    longest = len;
                }
                else if (len > secondLongest) {
                    secondLongest = len;
                }
            }

            ans = max(ans, 1 + longest + secondLongest);

            return 1 + longest;
        };

        dfs(0);

        return ans;
    }
};