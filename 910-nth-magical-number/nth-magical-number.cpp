class Solution {
public:
    static const int MOD = 1e9 + 7;

    long long gcd(long long x, long long y) {
        return y == 0 ? x : gcd(y, x % y);
    }

    int nthMagicalNumber(int n, int a, int b) {
        long long l = min(a, b);
        long long r = (long long)n * min(a, b);

        long long lcm = (long long)a / gcd(a, b) * b;

        while (l < r) {
            long long mid = l + (r - l) / 2;

            long long count =
                mid / a +
                mid / b -
                mid / lcm;

            if (count < n)
                l = mid + 1;
            else
                r = mid;
        }

        return l % MOD;
    }
};
