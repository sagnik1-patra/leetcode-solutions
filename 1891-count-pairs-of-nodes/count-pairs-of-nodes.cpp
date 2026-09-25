class Solution {
public:
    vector<int> countPairs(int n, vector<vector<int>>& edges,
                           vector<int>& queries) {
        
        vector<int> degree(n + 1, 0);

        // Count number of edges shared by each pair
        map<pair<int, int>, int> shared;

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            degree[u]++;
            degree[v]++;

            if (u > v) swap(u, v);
            shared[{u, v}]++;
        }

        vector<int> sortedDegree;

        for (int i = 1; i <= n; i++) {
            sortedDegree.push_back(degree[i]);
        }

        sort(sortedDegree.begin(), sortedDegree.end());

        vector<int> answers;

        for (int q : queries) {
            long long count = 0;

            // Count pairs whose degree sum > q
            int left = 0;
            int right = n - 1;

            while (left < right) {
                if (sortedDegree[left] + sortedDegree[right] > q) {
                    count += right - left;
                    right--;
                } else {
                    left++;
                }
            }

            // Correct pairs that have direct edges between them.
            // Shared edges were counted twice in degree[u] + degree[v].
            for (auto& entry : shared) {
                int u = entry.first.first;
                int v = entry.first.second;
                int common = entry.second;

                int sum = degree[u] + degree[v];

                if (sum > q && sum - common <= q) {
                    count--;
                }
            }

            answers.push_back((int)count);
        }

        return answers;
    }
};