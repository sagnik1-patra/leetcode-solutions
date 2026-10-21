
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        nums.erase(unique(nums.begin(), nums.end()), nums.end());

        int m = nums.size();
        int ans = n;
        int right = 0;

        for (int left = 0; left < m; left++) {

            while (right < m &&
                   nums[right] < nums[left] + (long long)n) {
                right++;
            }

            int count = right - left;

            ans = min(ans, n - count);
        }

        return ans;
    }
};
