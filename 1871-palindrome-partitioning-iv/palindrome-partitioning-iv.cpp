class Solution {
public:
    bool checkPartitioning(string s) {
        int n = s.size();

        // palindrome[i][j] = true if s[i...j] is a palindrome
        vector<vector<bool>> palindrome(
            n, vector<bool>(n, false)
        );

        // Build palindrome DP table
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] &&
                    (j - i <= 2 || palindrome[i + 1][j - 1])) {
                    palindrome[i][j] = true;
                }
            }
        }

        // Try all two split positions
        for (int i = 0; i < n - 2; i++) {
            if (!palindrome[0][i])
                continue;

            for (int j = i + 1; j < n - 1; j++) {
                if (palindrome[i + 1][j] &&
                    palindrome[j + 1][n - 1]) {
                    return true;
                }
            }
        }

        return false;
    }
};