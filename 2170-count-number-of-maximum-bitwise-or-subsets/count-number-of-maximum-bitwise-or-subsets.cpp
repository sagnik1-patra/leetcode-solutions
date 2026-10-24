
class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int maxOR = 0;
        int count = 0;

        for (int num : nums) {
            maxOR |= num;
        }

        for (int mask = 1; mask < (1 << n); mask++) {
            int currentOR = 0;

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    currentOR |= nums[i];
                }
            }

            if (currentOR == maxOR) {
                count++;
            }
        }

        return count;
    }
};
