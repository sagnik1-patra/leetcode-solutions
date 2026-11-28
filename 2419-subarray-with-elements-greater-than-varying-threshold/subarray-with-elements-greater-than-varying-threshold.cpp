class Solution {
public:
    int validSubarraySize(vector<int>& nums, int threshold) {
        int n = nums.size();

        stack<int> st;

        for (int i = 0; i <= n; i++) {

            while (!st.empty() &&
                   (i == n || nums[st.top()] >= nums[i])) {

                int height = nums[st.top()];
                st.pop();

                int left = st.empty() ? -1 : st.top();

                int width = i - left - 1;

                if (1LL * height * width > threshold)
                    return width;
            }

            st.push(i);
        }

        return -1;
    }
};