class Solution {
public:
    int largestPalindrome(int n) {
        if (n == 1) return 9;               // known edge case

        long long mod = 1337;
        long long lo = 1;
        for (int i = 1; i < n; ++i) lo *= 10;   // 10^(n-1)
        long long hi = lo * 10 - 1;             // 10^n - 1

        for (long long left = hi; left >= lo; --left) {
            // Build even-length palindrome by mirroring `left`
            long long pal = buildPalindrome(left);

            // Try to factor pal = a * b with both a, b in [lo, hi]
            for (long long a = hi; a * a >= pal; --a) {
                if (pal % a == 0) {
                    long long b = pal / a;
                    if (b >= lo && b <= hi) {
                        return (int)(pal % mod);
                    }
                }
            }
            // continue with next smaller left
        }
        // The loop above always finds an answer for n in [1..8]
        return -1; // should never hit
    }

private:
    static long long buildPalindrome(long long left) {
        long long x = left;
        long long pal = left;
        while (x > 0) {
            pal = pal * 10 + (x % 10);
            x /= 10;
        }
        return pal;
    }
};