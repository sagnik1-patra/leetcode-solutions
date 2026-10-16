
class Solution {
public:
    int minNonZeroProduct(int p) {
        long long mod = 1e9 + 7;

        long long maxNum = (1LL << p) - 1;
        long long base = (maxNum - 1) % mod;
        long long power = (1LL << (p - 1)) - 1;

        long long result = 1;

        while (power > 0) {
            if (power % 2 == 1) {
                result = (result * base) % mod;
            }

            base = (base * base) % mod;
            power /= 2;
        }

        return (result * (maxNum % mod)) % mod;
    }
};
