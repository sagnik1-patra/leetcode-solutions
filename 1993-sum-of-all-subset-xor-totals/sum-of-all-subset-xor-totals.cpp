class Solution {
public:
    int dfs(vector<int>& nums, int index, int currentXOR) {
        // All elements have been considered
        if (index == nums.size()) {
            return currentXOR;
        }

        // Option 1: Do not include nums[index]
        int exclude = dfs(nums, index + 1, currentXOR);

        // Option 2: Include nums[index]
        int include = dfs(nums, index + 1, currentXOR ^ nums[index]);

        return exclude + include;
    }

    int subsetXORSum(vector<int>& nums) {
        return dfs(nums, 0, 0);
    }
};