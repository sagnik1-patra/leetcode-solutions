class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long xorTotal = 0;
        for (int num : nums) {
            xorTotal ^= num;
        }

        // Find rightmost set bit
        long diffBit = xorTotal & (-xorTotal);

        int a = 0, b = 0;
        for (int num : nums) {
            if (num & diffBit)
                a ^= num;
            else
                b ^= num;
        }

        return {a, b};
    }
};
