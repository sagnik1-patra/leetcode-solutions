class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long miss = 1; // smallest sum in [1..n] we cannot form yet
        int i = 0, patches = 0;
        int m = nums.size();

        // While there exists a number in [1..n] we can't form
        while (miss <= n) {
            if (i < m && nums[i] <= miss) {
                // Use nums[i] to extend coverage: [1..miss) -> [1..miss+nums[i])
                miss += nums[i++];
            } else {
                // Patch with 'miss' itself to double the reachable range
                ++patches;
                miss += miss;
            }
        }
        return patches;
    }
};
