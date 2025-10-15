class Solution {
public:
    int minSteps(int n) {
        if (n == 1) return 0;

        int ans = 0;
        for (int d = 2; d * d <= n; ++d) {
            while (n % d == 0) {
                ans += d;
                n /= d;
            }
        }
        if (n > 1) ans += n;  // remaining prime factor
        return ans;
    }
};
