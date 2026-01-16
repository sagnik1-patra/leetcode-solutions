class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = 0;

        // Fix the top row
        for (int top = 0; top < m; top++) {
            vector<int> colSum(n, 0);

            // Extend bottom row
            for (int bottom = top; bottom < m; bottom++) {
                for (int c = 0; c < n; c++) {
                    colSum[c] += matrix[bottom][c];
                }

                // Count subarrays with sum = target in colSum
                unordered_map<int, int> mp;
                mp[0] = 1;
                int currSum = 0;

                for (int val : colSum) {
                    currSum += val;
                    if (mp.count(currSum - target)) {
                        ans += mp[currSum - target];
                    }
                    mp[currSum]++;
                }
            }
        }

        return ans;
    }
};
