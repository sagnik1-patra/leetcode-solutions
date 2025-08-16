class Solution {
public:
    int integerBreak(int n) {
        if (n <= 3) return n - 1;           // must split into at least two parts
        long long res = 1;
        // Use as many 3's as possible; replace 3+1 with 2+2 for better product
        while (n > 4) {                      // leave n in {2,3,4}
            res *= 3;
            n -= 3;
        }
        res *= n;                            // multiply by the remainder (2,3, or 4)
        return (int)res;
    }
};
