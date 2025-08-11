class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;  // stores indices of useful elements in current window
        vector<int> result;

        for (int i = 0; i < nums.size(); ++i) {
            // Remove indices out of current window range
            while (!dq.empty() && dq.front() <= i - k)
                dq.pop_front();

            // Remove indices whose corresponding values are less than nums[i]
            while (!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();

            // Add current index
            dq.push_back(i);

            // Start adding max values to result once we reach size k
            if (i >= k - 1)
                result.push_back(nums[dq.front()]);
        }

        return result;
    }
};