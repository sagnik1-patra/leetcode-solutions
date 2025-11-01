class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        unordered_set<int> primes = {2, 3, 5, 7, 11, 13, 17, 19};
        int count = 0;

        for (int n = left; n <= right; ++n) {
            int bits = __builtin_popcount(n); // built-in bit count
            if (primes.count(bits)) count++;
        }

        return count;
    }
};
