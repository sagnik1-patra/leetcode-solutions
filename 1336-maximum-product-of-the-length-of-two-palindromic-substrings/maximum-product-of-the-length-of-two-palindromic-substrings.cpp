
class Solution {
public:
    long long maxProduct(string s) {
        int n = s.size();

        vector<int> d(n, 0);
        int l = 0, r = -1;

        // Manacher's algorithm for odd-length palindromes
        for (int i = 0; i < n; i++) {
            int k = (i > r) ? 1 : min(d[l + r - i], r - i + 1);

            while (i - k >= 0 && i + k < n &&
                   s[i - k] == s[i + k]) {
                k++;
            }

            d[i] = k;
            k--;

            if (i + k > r) {
                l = i - k;
                r = i + k;
            }
        }

        vector<int> left(n, 0), right(n, 0);

        // Longest palindrome ending at each position
        for (int i = 0; i < n; i++) {
            int end = i + d[i] - 1;
            left[end] = max(left[end], 2 * d[i] - 1);
        }

        for (int i = n - 2; i >= 0; i--) {
            left[i] = max(left[i], left[i + 1] - 2);
        }

        for (int i = 1; i < n; i++) {
            left[i] = max(left[i], left[i - 1]);
        }

        // Longest palindrome starting at each position
        for (int i = 0; i < n; i++) {
            int start = i - d[i] + 1;
            right[start] = max(right[start], 2 * d[i] - 1);
        }

        for (int i = 1; i < n; i++) {
            right[i] = max(right[i], right[i - 1] - 2);
        }

        for (int i = n - 2; i >= 0; i--) {
            right[i] = max(right[i], right[i + 1]);
        }

        long long ans = 0;

        // Try every possible split
        for (int i = 0; i < n - 1; i++) {
            ans = max(ans, 1LL * left[i] * right[i + 1]);
        }

        return ans;
    }
};
