
class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        vector<int> freq(1001, 0);

        int ans = 0, maxFreq = 0;

        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == key) {
                int target = nums[i + 1];
                freq[target]++;

                if (freq[target] > maxFreq) {
                    maxFreq = freq[target];
                    ans = target;
                }
            }
        }

        return ans;
    }
};
