class Solution {
    vector<int> nums;
    mt19937 rng;
public:
    Solution(vector<int>& nums) : nums(nums), rng(random_device{}()) {}

    int pick(int target) {
        int ans = -1, cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                cnt++;
                uniform_int_distribution<int> dist(1, cnt);
                if (dist(rng) == 1) ans = i;
            }
        }
        return ans;
    }
};
