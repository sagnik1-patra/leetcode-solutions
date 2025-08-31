class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return false;

        vector<int> st; // decreasing stack of potential '3's
        long long third = LLONG_MIN; // best '2' so far (must be < current '3')

        for (int i = n - 1; i >= 0; --i) {
            if (nums[i] < third) return true; // nums[i] is '1'
            while (!st.empty() && st.back() < nums[i]) {
                third = st.back(); // popped value is a better '2'
                st.pop_back();
            }
            st.push_back(nums[i]); // nums[i] becomes a new '3' candidate
        }
        return false;
    }
};
