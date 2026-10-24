
class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> nums;

        for (auto row : grid) {
            for (int num : row) {
                nums.push_back(num);
            }
        }

        sort(nums.begin(), nums.end());

        int target = nums[nums.size() / 2];
        int operations = 0;

        for (int num : nums) {
            if ((num - target) % x != 0) {
                return -1;
            }

            operations += abs(num - target) / x;
        }

        return operations;
    }
};
