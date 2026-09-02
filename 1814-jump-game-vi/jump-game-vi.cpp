class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> dp(n);
        deque<int> dq;

        dp[0] = nums[0];
        dq.push_back(0);

        for (int i = 1; i < n; i++) {

            // Remove indices that are more than k steps away
            while (!dq.empty() && dq.front() < i - k) {
                dq.pop_front();
            }

            // Best previous score in the last k positions
            dp[i] = nums[i] + dp[dq.front()];

            // Maintain decreasing order of dp values
            while (!dq.empty() && dp[dq.back()] <= dp[i]) {
                dq.pop_back();
            }

            dq.push_back(i);
        }

        return dp[n - 1];
    }
};