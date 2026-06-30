class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> maxD, minD;
        int left = 0, result = 0;
        
        for (int right = 0; right < nums.size(); right++) {
            // maintain max deque
            while (!maxD.empty() && nums[maxD.back()] < nums[right]) {
                maxD.pop_back();
            }
            maxD.push_back(right);
            
            // maintain min deque
            while (!minD.empty() && nums[minD.back()] > nums[right]) {
                minD.pop_back();
            }
            minD.push_back(right);
            
            // shrink window if invalid
            while (nums[maxD.front()] - nums[minD.front()] > limit) {
                if (maxD.front() == left) maxD.pop_front();
                if (minD.front() == left) minD.pop_front();
                left++;
            }
            
            result = max(result, right - left + 1);
        }
        
        return result;
    }
};