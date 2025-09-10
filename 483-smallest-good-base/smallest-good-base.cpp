class Solution {
    using u128 = __uint128_t;
    using u64 = unsigned long long;

    // Compute 1 + k + k^2 + ... + k^(L-1), but stop if it exceeds n
    static u128 geomSum(u64 k, int L, u128 n) {
        u128 sum = 1;
        u128 term = 1;
        for (int i = 1; i < L; ++i) {
            term *= k;             // k^i
            if (term > n) return n + 1; // early stop (exceeds n)
            sum += term;
            if (sum > n) return n + 1;  // early stop
        }
        return sum;
    }

public:
    string smallestGoodBase(string s) {
        u64 n = stoull(s);

        // Max digits (all 1's) is floor(log2(n)) + 1
        int maxL = 64 - __builtin_clzll(n); // works for n>0

        // Try longer lengths first (gives smaller base)
        for (int L = maxL; L >= 2; --L) {
            // k is in [2, floor(n^(1/(L-1)))]
            long double root = pow((long double)n, 1.0L / (L - 1));
            u64 hi = (u64)floor(root) + 1; // +1 to be safe against fp underestimation
            if (hi < 2) hi = 2;

            u64 lo = 2;
            if (hi < lo) continue;

            // Binary search for k
            while (lo <= hi) {
                u64 mid = lo + (hi - lo) / 2;
                u128 sum = geomSum(mid, L, (u128)n);
                if (sum == n) {
                    return to_string(mid);
                } else if (sum < n) {
                    lo = mid + 1;
                } else {
                    if (mid == 0) break; // safety
                    hi = mid - 1;
                }
            }
        }

        // Fallback: base n-1 gives "11"
        return to_string(n - 1);
    }
};