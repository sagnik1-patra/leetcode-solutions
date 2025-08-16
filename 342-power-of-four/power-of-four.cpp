class Solution {
public:
    bool isPowerOfFour(int n) {
        // Must be positive
        if (n <= 0) return false;
        // Check if it's a power of 2: only one bit set
        if (n & (n - 1)) return false;
        // Ensure the single '1' bit is in an odd position (bitmask 0x55555555 = 0101... in 32 bits)
        return (n & 0x55555555) != 0;
    }
};
