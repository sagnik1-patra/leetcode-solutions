class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        sort(arr.begin(), arr.end());
        int n = arr.size();

        unordered_map<int, long long> dp;  // dp[val] = number of trees rooted at val

        for (int i = 0; i < n; i++) {
            long long count = 1;  // single-node tree
            for (int j = 0; j < i; j++) {
                if (arr[i] % arr[j] == 0) {
                    int right = arr[i] / arr[j];
                    if (dp.count(right)) {
                        count = (count + dp[arr[j]] * dp[right]) % MOD;
                    }
                }
            }
            dp[arr[i]] = count;
        }

        long long total = 0;
        for (auto &p : dp) total = (total + p.second) % MOD;

        return (int)total;
    }
};