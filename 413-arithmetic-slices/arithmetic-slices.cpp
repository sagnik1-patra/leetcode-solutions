class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;
        
        int result = 0;
        int curr = 0; // count of arithmetic subarrays ending at current index
        
        for (int i = 2; i < n; i++) {
            if (nums[i] - nums[i-1] == nums[i-1] - nums[i-2]) {
                curr += 1;
                result += curr;
            } else {
                curr = 0; // reset when difference breaks
            }
        }
        return result;
    }
};
