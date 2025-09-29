class Solution {
public:
    int count = 0;

    void dfs(int pos, int n, vector<bool>& used) {
        if (pos > n) {
            count++;
            return;
        }
        for (int num = 1; num <= n; num++) {
            if (!used[num] && (num % pos == 0 || pos % num == 0)) {
                used[num] = true;
                dfs(pos + 1, n, used);
                used[num] = false;
            }
        }
    }

    int countArrangement(int n) {
        vector<bool> used(n + 1, false);
        dfs(1, n, used);
        return count;
    }
};