class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size(), n = mat[0].size();

        // Step 1: Prefix sum
        vector<vector<int>> prefix(m+1, vector<int>(n+1, 0));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                prefix[i][j] = mat[i-1][j-1]
                             + prefix[i-1][j]
                             + prefix[i][j-1]
                             - prefix[i-1][j-1];
            }
        }

        // Check if square of size k exists
        auto can = [&](int k) {
            for (int i = k; i <= m; i++) {
                for (int j = k; j <= n; j++) {
                    int sum = prefix[i][j]
                            - prefix[i-k][j]
                            - prefix[i][j-k]
                            + prefix[i-k][j-k];

                    if (sum <= threshold)
                        return true;
                }
            }
            return false;
        };

        // Step 2: Binary search
        int left = 0, right = min(m, n), ans = 0;

        while (left <= right) {
            int mid = (left + right) / 2;

            if (can(mid)) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return ans;
    }
};