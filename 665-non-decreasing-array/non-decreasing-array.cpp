class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int count = 0;  // count of modifications

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < nums[i - 1]) {
                count++;
                if (count > 1) return false;

                // If modifying nums[i-1] keeps array non-decreasing
                if (i == 1 || nums[i] >= nums[i - 2]) {
                    nums[i - 1] = nums[i];
                } 
                // Else modify nums[i] instead
                else {
                    nums[i] = nums[i - 1];
                }
            }
        }

        return true;
    }
};
