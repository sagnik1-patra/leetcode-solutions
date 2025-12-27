class Solution {
public:
    string shortestSuperstring(vector<string>& words) {
        int n = words.size();

        // overlap[i][j] = number of chars to skip from words[j]
        vector<vector<int>> overlap(n, vector<int>(n, 0));

        // compute overlaps
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                int len = min(words[i].size(), words[j].size());
                for (int k = len; k >= 0; k--) {
                    if (words[i].substr(words[i].size() - k) ==
                        words[j].substr(0, k)) {
                        overlap[i][j] = k;
                        break;
                    }
                }
            }
        }

        int N = 1 << n;
        vector<vector<string>> dp(N, vector<string>(n, ""));

        // base cases
        for (int i = 0; i < n; i++) {
            dp[1 << i][i] = words[i];
        }

        // DP
        for (int mask = 1; mask < N; mask++) {
            for (int i = 0; i < n; i++) {
                if (!(mask & (1 << i)) || dp[mask][i].empty()) continue;

                for (int j = 0; j < n; j++) {
                    if (mask & (1 << j)) continue;

                    int nextMask = mask | (1 << j);
                    string candidate =
                        dp[mask][i] + words[j].substr(overlap[i][j]);

                    if (dp[nextMask][j].empty() ||
                        candidate.size() < dp[nextMask][j].size()) {
                        dp[nextMask][j] = candidate;
                    }
                }
            }
        }

        // pick shortest final result
        string ans = "";
        for (int i = 0; i < n; i++) {
            string cur = dp[N - 1][i];
            if (!cur.empty() && (ans.empty() || cur.size() < ans.size())) {
                ans = cur;
            }
        }

        return ans;
    }
};
