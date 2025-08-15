class Solution {
public:
    bool isPowerOfThree(int n) {
        // 3^19 = 1162261467 is the largest power of 3 within 32-bit signed int
        return n > 0 && 1162261467 % n == 0;
    }
};
