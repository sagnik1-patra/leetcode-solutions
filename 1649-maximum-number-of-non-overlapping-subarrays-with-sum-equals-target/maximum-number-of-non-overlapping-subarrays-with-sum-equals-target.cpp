class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        unordered_set<int> seen;
        seen.insert(0);
        
        int sum = 0;
        int count = 0;
        
        for (int x : nums) {
            sum += x;
            
            if (seen.count(sum - target)) {
                count++;
                
                // reset
                sum = 0;
                seen.clear();
                seen.insert(0);
            } else {
                seen.insert(sum);
            }
        }
        
        return count;
    }
};