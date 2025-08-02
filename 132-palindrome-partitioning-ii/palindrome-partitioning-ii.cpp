class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));
        vector<int> dp(n, 0);

        // Precompute palindrome substrings
        for (int end = 0; end < n; ++end) {
            int minCut = end; // worst case: cut between each character
            for (int start = 0; start <= end; ++start) {
                if (s[start] == s[end] && (end - start <= 2 || isPalindrome[start + 1][end - 1])) {
                    isPalindrome[start][end] = true;
                    minCut = (start == 0) ? 0 : min(minCut, dp[start - 1] + 1);
                }
            }
            dp[end] = minCut;
        }

        return dp[n - 1];
    }
};
