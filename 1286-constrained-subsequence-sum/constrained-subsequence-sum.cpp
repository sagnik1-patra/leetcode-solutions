class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n);
        deque<int> dq;

        int ans = nums[0];

        for (int i = 0; i < n; i++) {
            dp[i] = nums[i];

            if (!dq.empty()) {
                dp[i] += max(0, dp[dq.front()]);
            }

            ans = max(ans, dp[i]);

            while (!dq.empty() && dp[dq.back()] <= dp[i]) {
                dq.pop_back();
            }

            dq.push_back(i);

            if (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }
        }

        return ans;
    }
};