class Solution {
public:
    vector<int> parent, rank;

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);

        if (rootA == rootB)
            return;

        if (rank[rootA] < rank[rootB]) {
            swap(rootA, rootB);
        }

        parent[rootB] = rootA;

        if (rank[rootA] == rank[rootB]) {
            rank[rootA]++;
        }
    }

    int minimumHammingDistance(vector<int>& source,
                               vector<int>& target,
                               vector<vector<int>>& allowedSwaps) {
        int n = source.size();

        parent.resize(n);
        rank.assign(n, 0);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        // Connect all indices that can be swapped
        for (auto& swapPair : allowedSwaps) {
            unite(swapPair[0], swapPair[1]);
        }

        // Store frequencies of source values in each component
        unordered_map<int, unordered_map<int, int>> freq;

        for (int i = 0; i < n; i++) {
            int root = find(i);
            freq[root][source[i]]++;
        }

        int distance = 0;

        // Try to match each target value inside its component
        for (int i = 0; i < n; i++) {
            int root = find(i);

            if (freq[root][target[i]] > 0) {
                freq[root][target[i]]--;
            } else {
                distance++;
            }
        }

        return distance;
    }
};