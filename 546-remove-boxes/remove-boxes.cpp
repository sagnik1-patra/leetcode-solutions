class Solution {
public:
    int dp[100][100][100]; // memo

    int removeBoxes(vector<int>& boxes) {
        memset(dp, -1, sizeof(dp));
        return solve(boxes, 0, boxes.size()-1, 0);
    }

    int solve(vector<int>& boxes, int l, int r, int k) {
        if (l > r) return 0;
        if (dp[l][r][k] != -1) return dp[l][r][k];

        // Option 1: remove boxes[l] (and its k companions) immediately
        int res = (k+1) * (k+1) + solve(boxes, l+1, r, 0);

        // Option 2: try merging boxes[l] with future same-colored box
        for (int i = l+1; i <= r; i++) {
            if (boxes[i] == boxes[l]) {
                res = max(res, solve(boxes, l+1, i-1, 0) + solve(boxes, i, r, k+1));
            }
        }

        return dp[l][r][k] = res;
    }
};