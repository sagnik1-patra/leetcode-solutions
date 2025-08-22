class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for (int x : nums) total += x;
        if (total & 1) return false;
        int target = total / 2;

        std::bitset<20001> bs; // max sum = 200*100
        bs[0] = 1;
        for (int x : nums) bs |= (bs << x);
        return bs[target];
    }
};