class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;

        // Step 1: build decreasing stack of indices
        for (int i = 0; i < n; i++) {
            if (st.empty() || nums[i] < nums[st.top()]) {
                st.push(i);
            }
        }

        int ans = 0;

        // Step 2: scan from right to left
        for (int j = n - 1; j >= 0; j--) {
            while (!st.empty() && nums[st.top()] <= nums[j]) {
                ans = max(ans, j - st.top());
                st.pop();
            }
        }

        return ans;
    }
};
