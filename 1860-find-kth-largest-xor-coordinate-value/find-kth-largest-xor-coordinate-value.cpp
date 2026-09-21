class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> prefix(m + 1, vector<int>(n + 1, 0));

        // Min-heap containing the k largest values
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {

                prefix[i][j] =
                    matrix[i - 1][j - 1] ^
                    prefix[i - 1][j] ^
                    prefix[i][j - 1] ^
                    prefix[i - 1][j - 1];

                pq.push(prefix[i][j]);

                if (pq.size() > k) {
                    pq.pop();
                }
            }
        }

        return pq.top();
    }
};