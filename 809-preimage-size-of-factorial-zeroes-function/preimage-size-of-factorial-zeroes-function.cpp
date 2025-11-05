class Solution {
public:
    // Function to count trailing zeros in x!
    long long f(long long x) {
        long long cnt = 0;
        while (x > 0) {
            x /= 5;
            cnt += x;
        }
        return cnt;
    }

    int preimageSizeFZF(int k) {
        // Binary search for smallest x where f(x) >= k
        long long left = 0, right = 5LL * (k + 1);  // upper bound estimate

        while (left < right) {
            long long mid = left + (right - left) / 2;
            if (f(mid) < k)
                left = mid + 1;
            else
                right = mid;
        }

        // left is now the smallest x where f(x) >= k
        if (f(left) != k) return 0;

        // There are always exactly 5 consecutive x giving same k
        return 5;
    }
};