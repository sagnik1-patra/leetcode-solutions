
class Solution {
public:
    int colorTheGrid(int m, int n) {
        const int MOD = 1e9 + 7;
        vector<vector<int>> states;
        vector<int> current;

        // Generate all valid column colorings
        function<void(int)> generate = [&](int row) {
            if (row == m) {
                states.push_back(current);
                return;
            }

            for (int color = 0; color < 3; color++) {
                if (row > 0 && current.back() == color)
                    continue;

                current.push_back(color);
                generate(row + 1);
                current.pop_back();
            }
        };

        generate(0);

        int k = states.size();

        // Precompute compatible columns
        vector<vector<int>> compatible(k);

        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                bool valid = true;

                for (int r = 0; r < m; r++) {
                    if (states[i][r] == states[j][r]) {
                        valid = false;
                        break;
                    }
                }

                if (valid)
                    compatible[i].push_back(j);
            }
        }

        // DP initialization
        vector<int> dp(k, 1);

        // Process remaining columns
        for (int col = 1; col < n; col++) {
            vector<int> next(k, 0);

            for (int i = 0; i < k; i++) {
                for (int j : compatible[i]) {
                    next[j] = (next[j] + dp[i]) % MOD;
                }
            }

            dp = next;
        }

        long long ans = 0;

        for (int ways : dp) {
            ans = (ans + ways) % MOD;
        }

        return (int)ans;
    }
};
