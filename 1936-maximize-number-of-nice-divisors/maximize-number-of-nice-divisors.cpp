class Solution {
public:
    const long long MOD = 1e9 + 7;

    long long power(long long base, long long exp) {
        long long result = 1;

        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * base) % MOD;
            }

            base = (base * base) % MOD;
            exp /= 2;
        }

        return result;
    }

    int maxNiceDivisors(int primeFactors) {

        if (primeFactors <= 3)
            return primeFactors;

        long long q = primeFactors / 3;
        int r = primeFactors % 3;

        // Completely divisible by 3
        if (r == 0) {
            return power(3, q);
        }

        // Remainder 1:
        // Replace 3 + 1 with 2 + 2
        if (r == 1) {
            return (power(3, q - 1) * 4) % MOD;
        }

        // Remainder 2
        return (power(3, q) * 2) % MOD;
    }
};