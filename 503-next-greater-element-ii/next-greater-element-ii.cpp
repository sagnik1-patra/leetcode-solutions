class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        vector<int> st; // stack of indices, values in strictly decreasing order

        for (int i = 2*n - 1; i >= 0; --i) {
            int idx = i % n;
            while (!st.empty() && nums[st.back()] <= nums[idx]) st.pop_back();
            if (!st.empty()) ans[idx] = nums[st.back()];
            st.push_back(idx);
        }
        return ans;
    }
};
