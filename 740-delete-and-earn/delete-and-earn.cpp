class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxNum = *max_element(nums.begin(), nums.end());
        vector<int> points(maxNum + 1, 0);

        // Aggregate points for each number
        for (int num : nums)
            points[num] += num;

        // Apply House Robber DP
        int take = 0, skip = 0;
        for (int i = 0; i <= maxNum; ++i) {
            int takeNew = skip + points[i];
            int skipNew = max(skip, take);
            take = takeNew;
            skip = skipNew;
        }

        return max(take, skip);
    }
};
