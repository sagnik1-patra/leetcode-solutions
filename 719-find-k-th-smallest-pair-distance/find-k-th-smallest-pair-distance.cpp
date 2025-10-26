class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int left = 0;
        int right = nums.back() - nums.front();

        auto countPairs = [&](int mid) {
            int count = 0;
            int i = 0;
            for (int j = 0; j < n; ++j) {
                while (nums[j] - nums[i] > mid)
                    ++i;
                count += j - i;
            }
            return count;
        };

        while (left < right) {
            int mid = (left + right) / 2;
            if (countPairs(mid) >= k)
                right = mid;
            else
                left = mid + 1;
        }

        return left;
    }
};
