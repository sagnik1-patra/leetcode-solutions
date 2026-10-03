class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int xorSum = 0;

        // XOR of all elements
        for (int x : nums) {
            xorSum ^= x;
        }

        int mask = (1 << maximumBit) - 1;

        vector<int> answer;

        // Process from the last element backwards
        for (int i = nums.size() - 1; i >= 0; i--) {

            int k = xorSum ^ mask;

            answer.push_back(k);

            // Remove nums[i] from the XOR
            xorSum ^= nums[i];
        }

        return answer;
    }
};