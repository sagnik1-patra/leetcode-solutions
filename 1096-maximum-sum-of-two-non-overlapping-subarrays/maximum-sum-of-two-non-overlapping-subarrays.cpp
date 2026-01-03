class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);

        // Prefix sum
        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + nums[i];

        // Helper lambda
        auto solve = [&](int L, int M) {
            int maxL = 0;
            int res = 0;

            // i is the starting index of M-length subarray
            for (int i = L + M; i <= n; i++) {
                // Best L subarray ending before M starts
                maxL = max(maxL, prefix[i - M] - prefix[i - M - L]);

                // Current M subarray
                int sumM = prefix[i] - prefix[i - M];

                res = max(res, maxL + sumM);
            }
            return res;
        };

        // Try both orders
        return max(solve(firstLen, secondLen),
                   solve(secondLen, firstLen));
    }
};
