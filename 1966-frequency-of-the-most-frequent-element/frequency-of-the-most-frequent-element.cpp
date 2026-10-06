class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        long long sum = 0;
        int left = 0;
        int answer = 1;

        for (int right = 0; right < nums.size(); right++) {

            sum += nums[right];

            // Operations needed to make every element
            // in the window equal to nums[right]
            while ((long long)nums[right] * (right - left + 1)
                   - sum > k) {

                sum -= nums[left];
                left++;
            }

            answer = max(answer, right - left + 1);
        }

        return answer;
    }
};