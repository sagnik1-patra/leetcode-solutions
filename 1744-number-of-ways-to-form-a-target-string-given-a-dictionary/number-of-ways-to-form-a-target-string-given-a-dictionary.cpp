class Solution {
public:
    int numWays(vector<string>& words, string target) {
        const int MOD = 1e9 + 7;

        int m = words[0].size();
        int n = target.size();

        // freq[col][ch] = how many words have character ch at this column
        vector<vector<int>> freq(m, vector<int>(26, 0));

        for (const string& word : words) {
            for (int col = 0; col < m; col++) {
                freq[col][word[col] - 'a']++;
            }
        }

        // dp[i] = number of ways to form first i characters of target
        vector<long long> dp(n + 1, 0);
        dp[0] = 1;

        // Process columns from left to right
        for (int col = 0; col < m; col++) {

            // Go backwards so same column isn't used twice
            for (int i = n - 1; i >= 0; i--) {

                int count = freq[col][target[i] - 'a'];

                dp[i + 1] =
                    (dp[i + 1] + dp[i] * count) % MOD;
            }
        }

        return dp[n];
    }
};