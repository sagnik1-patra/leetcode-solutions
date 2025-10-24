class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
        int n = stickers.size();
        vector<vector<int>> stickerCount(n, vector<int>(26, 0));

        // Precompute frequency of each letter in every sticker
        for (int i = 0; i < n; ++i)
            for (char c : stickers[i])
                stickerCount[i][c - 'a']++;

        unordered_map<string, int> memo;
        memo[""] = 0; // base case: no stickers needed for empty target

        return dfs(target, stickerCount, memo);
    }

private:
    int dfs(string target, vector<vector<int>>& stickerCount, unordered_map<string, int>& memo) {
        if (memo.count(target)) return memo[target];

        vector<int> targetCount(26, 0);
        for (char c : target) targetCount[c - 'a']++;

        int res = INT_MAX;
        for (auto& sticker : stickerCount) {
            // Optimization: skip sticker if it doesn't contain target's first letter
            if (sticker[target[0] - 'a'] == 0) continue;

            string nextTarget;
            for (int i = 0; i < 26; ++i) {
                int remain = targetCount[i] - sticker[i];
                for (int j = 0; j < max(0, remain); ++j)
                    nextTarget += char('a' + i);
            }

            if (nextTarget.size() != target.size()) {
                int tmp = dfs(nextTarget, stickerCount, memo);
                if (tmp != -1)
                    res = min(res, 1 + tmp);
            }
        }
        memo[target] = (res == INT_MAX) ? -1 : res;
        return memo[target];
    }
};
