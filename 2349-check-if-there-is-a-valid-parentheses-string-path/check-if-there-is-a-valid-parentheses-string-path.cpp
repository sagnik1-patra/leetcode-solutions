class Solution {
public:
    int m, n;
    int dp[101][101][201];

    bool dfs(vector<vector<char>>& grid, int r, int c, int balance) {

        if (r >= m || c >= n)
            return false;

        if (grid[r][c] == '(')
            balance++;
        else
            balance--;

        // More closing parentheses than opening parentheses
        if (balance < 0)
            return false;

        // Remaining cells are insufficient to close parentheses
        int remaining = (m - 1 - r) + (n - 1 - c);

        if (balance > remaining)
            return false;

        // Reached destination
        if (r == m - 1 && c == n - 1)
            return balance == 0;

        // Previously calculated state
        if (dp[r][c][balance] != -1)
            return dp[r][c][balance];

        // Move down or right
        return dp[r][c][balance] =
            dfs(grid, r + 1, c, balance) ||
            dfs(grid, r, c + 1, balance);
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        // Valid parentheses string must have even length
        if ((m + n - 1) % 2 != 0)
            return false;

        // Check starting and ending characters
        if (grid[0][0] == ')' || grid[m - 1][n - 1] == '(')
            return false;

        memset(dp, -1, sizeof(dp));

        return dfs(grid, 0, 0, 0);
    }
};