
class Solution {
public:
    int dp[1001][1001];

    int solve(int i, int carpets, string &floor, int len) {
        int n = floor.size();

        if (i >= n) return 0;

        if (carpets == 0) {
            int count = 0;
            for (int j = i; j < n; j++) {
                if (floor[j] == '1') count++;
            }
            return count;
        }

        if (dp[i][carpets] != -1)
            return dp[i][carpets];

        // Option 1: Don't place a carpet
        int skip = (floor[i] == '1') +
                   solve(i + 1, carpets, floor, len);

        // Option 2: Place a carpet
        int take = solve(i + len, carpets - 1, floor, len);

        return dp[i][carpets] = min(skip, take);
    }

    int minimumWhiteTiles(string floor, int numCarpets,
                          int carpetLen) {
        memset(dp, -1, sizeof(dp));
        return solve(0, numCarpets, floor, carpetLen);
    }
};
