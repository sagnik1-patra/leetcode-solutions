class Solution {
public:
    int bitwiseComplement(int n) {
        // Special case
        if (n == 0) return 1;

        int mask = 0;
        int temp = n;

        // Build mask of 1s with same bit length as n
        while (temp > 0) {
            mask = (mask << 1) | 1;
            temp >>= 1;
        }

        return n ^ mask;
    }
};
