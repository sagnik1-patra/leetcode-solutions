class Solution {
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& relations, int k) {
        vector<int> prereq(n, 0);

        for (auto &r : relations) {
            int prev = r[0] - 1;
            int next = r[1] - 1;
            prereq[next] |= (1 << prev);
        }

        int totalMask = (1 << n) - 1;
        vector<int> dp(1 << n, 1e9);

        dp[0] = 0;

        for (int mask = 0; mask <= totalMask; mask++) {
            int canTake = 0;

            for (int course = 0; course < n; course++) {
                if ((mask & (1 << course)) == 0 &&
                    (prereq[course] & mask) == prereq[course]) {
                    canTake |= (1 << course);
                }
            }

            for (int sub = canTake; sub > 0; sub = (sub - 1) & canTake) {
                if (__builtin_popcount(sub) <= k) {
                    dp[mask | sub] = min(dp[mask | sub], dp[mask] + 1);
                }
            }
        }

        return dp[totalMask];
    }
};