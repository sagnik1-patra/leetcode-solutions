class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> index;
        
        // Value -> index mapping
        for (int i = 0; i < n; i++) {
            index[arr[i]] = i;
        }

        vector<vector<int>> dp(n, vector<int>(n, 2));
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int prev = arr[i] - arr[j];

                // Since array is strictly increasing
                if (prev < arr[j] && index.count(prev)) {
                    int k = index[prev];
                    dp[j][i] = dp[k][j] + 1;
                    ans = max(ans, dp[j][i]);
                }
            }
        }

        return ans >= 3 ? ans : 0;
    }
};
