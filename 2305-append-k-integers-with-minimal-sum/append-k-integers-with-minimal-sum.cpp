
class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        long long ans = 0;
        long long start = 1;

        for (int num : nums) {
            if (num < start)
                continue;

            if (num > start) {
                long long count = min((long long)k,
                                      (long long)num - start);

                ans += count * (2 * start + count - 1) / 2;

                k -= count;
                start += count;
            }

            if (k == 0)
                return ans;

            start = (long long)num + 1;
        }

        if (k > 0) {
            ans += (long long)k * (2 * start + k - 1) / 2;
        }

        return ans;
    }
};
