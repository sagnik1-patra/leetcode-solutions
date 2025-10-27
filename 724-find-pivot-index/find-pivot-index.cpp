class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        int leftSum = 0;

        for (int i = 0; i < nums.size(); ++i) {
            if (2 * leftSum + nums[i] == total)
                return i;
            leftSum += nums[i];
        }
        return -1;
    }
};
