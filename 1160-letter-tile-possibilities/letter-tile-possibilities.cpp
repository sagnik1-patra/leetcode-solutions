class Solution {
public:
    int dfs(vector<int>& count) {
        int res = 0;

        for (int i = 0; i < 26; i++) {
            if (count[i] == 0) continue;

            // choose this letter
            res++;                 // count this sequence
            count[i]--;
            res += dfs(count);     // extend sequence
            count[i]++;            // backtrack
        }

        return res;
    }

    int numTilePossibilities(string tiles) {
        vector<int> count(26, 0);
        for (char c : tiles) {
            count[c - 'A']++;
        }

        return dfs(count);
    }
};
