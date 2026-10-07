class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        int n = nums.size();
        const long long MOD = 1000000007;

        // Prefix sum
        vector<long long> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        // left[i]  = first valid position on left
        // right[i] = first valid position on right
        vector<int> left(n), right(n);

        stack<int> st;

        // Find previous smaller element
        for (int i = 0; i < n; i++) {

            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }

            if (st.empty()) {
                left[i] = 0;
            } else {
                left[i] = st.top() + 1;
            }

            st.push(i);
        }

        // Clear stack
        while (!st.empty()) {
            st.pop();
        }

        // Find next smaller element
        for (int i = n - 1; i >= 0; i--) {

            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }

            if (st.empty()) {
                right[i] = n - 1;
            } else {
                right[i] = st.top() - 1;
            }

            st.push(i);
        }

        long long answer = 0;

        // Calculate min-product
        for (int i = 0; i < n; i++) {

            long long sum =
                prefix[right[i] + 1] - prefix[left[i]];

            long long minProduct =
                sum * nums[i];

            answer = max(answer, minProduct);
        }

        return answer % MOD;
    }
};