class Solution {
public:
    int maxValueAfterReverse(vector<int>& nums) {
        int n = nums.size();
        int base = 0;
        
        // Step 1: base value
        for (int i = 0; i < n - 1; i++) {
            base += abs(nums[i] - nums[i + 1]);
        }
        
        int gain = 0;
        
        // Step 2: reverse prefix/suffix
        for (int i = 0; i < n - 1; i++) {
            gain = max(gain, 
                abs(nums[0] - nums[i + 1]) - abs(nums[i] - nums[i + 1]));
            
            gain = max(gain, 
                abs(nums[n - 1] - nums[i]) - abs(nums[i] - nums[i + 1]));
        }
        
        // Step 3: middle case
        int minMax = INT_MAX;
        int maxMin = INT_MIN;
        
        for (int i = 0; i < n - 1; i++) {
            int a = nums[i], b = nums[i + 1];
            
            minMax = min(minMax, max(a, b));
            maxMin = max(maxMin, min(a, b));
        }
        
        gain = max(gain, 2 * (maxMin - minMax));
        
        return base + gain;
    }
};