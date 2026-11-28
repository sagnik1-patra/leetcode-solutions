class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        int freq[101] = {0};
        int pairs = 0;

        for (int num : nums) {
            freq[num]++;

            if (freq[num] % 2 == 0) {
                pairs++;
            }
        }

        return {pairs, (int)nums.size() - 2 * pairs};
    }
};