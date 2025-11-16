class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int count = 0;

        // Every sequence can be represented as:
        // n = k*x + k*(k-1)/2  --> x must be positive integer
        // => (n - k*(k-1)/2) % k == 0  and > 0
        for (long long k = 1; k * (k - 1) / 2 < n; ++k) {
            if ((n - k * (k - 1) / 2) % k == 0)
                count++;
        }

        return count;
    }
};