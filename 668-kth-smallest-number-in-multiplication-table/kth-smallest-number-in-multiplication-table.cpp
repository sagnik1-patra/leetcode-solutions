class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int low = 1, high = m * n, ans = -1;

        auto countLessEqual = [&](int x) {
            int count = 0;
            for (int i = 1; i <= m; ++i)
                count += min(x / i, n);  // elements ≤ x in row i
            return count;
        };

        // Binary search on possible values
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (countLessEqual(mid) >= k) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
