
class Solution {
public:
    int waysToPartition(vector<int>& nums, int k) {
        int n = nums.size();

        long long total = 0;
        for (int x : nums) {
            total += x;
        }

        unordered_map<long long, int> left, right;

        long long prefix = 0;

        for (int i = 0; i < n - 1; i++) {
            prefix += nums[i];
            long long diff = 2 * prefix - total;
            right[diff]++;
        }

        int ans = right[0];
        prefix = 0;

        for (int i = 0; i < n; i++) {
            long long change = (long long)k - nums[i];

            int ways = left[change] + right[-change];

            ans = max(ans, ways);

            if (i < n - 1) {
                prefix += nums[i];
                long long diff = 2 * prefix - total;

                right[diff]--;
                left[diff]++;
            }
        }

        return ans;
    }
};
