class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0) {
            unsigned carry = (unsigned)(a & b) << 1; // carry
            a = a ^ b;   // sum without carry
            b = (int)carry; // add carry in next round
        }
        return a;
    }
};
