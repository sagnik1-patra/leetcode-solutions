class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        long first = LONG_MAX, second = LONG_MAX;
        for (int x : nums) {
            if (x <= first) first = x;          // best (smallest) candidate for the first number
            else if (x <= second) second = x;   // best candidate for the second number (> first)
            else return true;                   // found x > second > first
        }
        return false;
    }
};
