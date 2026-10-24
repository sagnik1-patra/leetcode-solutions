
class Solution {
public:
    int countHighestScoreNodes(vector<int>& parents) {
        int n = parents.size();

        vector<vector<int>> children(n);

        for (int i = 1; i < n; i++) {
            children[parents[i]].push_back(i);
        }

        // Iterative DFS to avoid recursion stack overflow
        vector<int> order;
        order.push_back(0);

        for (int i = 0; i < order.size(); i++) {
            int node = order[i];

            for (int child : children[node]) {
                order.push_back(child);
            }
        }

        vector<int> subtree(n, 1);

        long long maxScore = 0;
        int count = 0;

        // Process children before parents
        for (int i = n - 1; i >= 0; i--) {
            int node = order[i];
            long long score = 1;

            for (int child : children[node]) {
                subtree[node] += subtree[child];
                score *= subtree[child];
            }

            int remaining = n - subtree[node];

            if (remaining > 0) {
                score *= remaining;
            }

            if (score > maxScore) {
                maxScore = score;
                count = 1;
            }
            else if (score == maxScore) {
                count++;
            }
        }

        return count;
    }
};
