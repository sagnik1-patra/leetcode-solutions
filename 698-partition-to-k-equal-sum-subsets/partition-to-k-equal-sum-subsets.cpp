class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % k != 0) return false;
        int target = total / k;
        
        sort(nums.rbegin(), nums.rend()); // sort descending for pruning
        vector<int> subset(k, 0);
        
        return backtrack(nums, subset, k, target, 0);
    }
    
    bool backtrack(vector<int>& nums, vector<int>& subset, int k, int target, int index) {
        if (index == nums.size()) {
            for (int s : subset)
                if (s != target) return false;
            return true;
        }
        
        int num = nums[index];
        for (int i = 0; i < k; ++i) {
            if (subset[i] + num > target) continue;
            
            subset[i] += num;
            if (backtrack(nums, subset, k, target, index + 1))
                return true;
            subset[i] -= num;
            
            // pruning: if this subset is empty or same as previous one
            if (subset[i] == 0) break;
        }
        return false;
    }
};
