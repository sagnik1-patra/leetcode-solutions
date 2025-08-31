class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        int mid = n / 2;
        nth_element(nums.begin(), nums.begin() + mid, nums.end());
        long long med = nums[mid];

        long long ans = 0;
        for (long long x : nums) ans += llabs(x - med);
        return (int)ans; // fits in 32-bit per problem
    }
};
