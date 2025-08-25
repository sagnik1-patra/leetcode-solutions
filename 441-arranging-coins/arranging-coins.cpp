class Solution {
public:
    int arrangeCoins(int n) {
        long long lo = 0, hi = n; // k is in [0, n]
        while (lo <= hi) {
            long long mid = (lo + hi) / 2;
            long long need = mid * (mid + 1) / 2; // coins to fill mid rows
            if (need == n) return (int)mid;
            if (need < n) lo = mid + 1;
            else hi = mid - 1;
        }
        return (int)hi; // largest k with k(k+1)/2 <= n
    }
};
