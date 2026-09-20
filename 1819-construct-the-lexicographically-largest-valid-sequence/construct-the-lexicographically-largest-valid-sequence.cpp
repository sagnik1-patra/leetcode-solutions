class Solution {
public:
    bool solve(int index, vector<int>& ans, vector<bool>& used, int n) {
        int size = ans.size();

        // Find the next empty position
        while (index < size && ans[index] != 0) {
            index++;
        }

        // All positions filled
        if (index == size) {
            return true;
        }

        // Try larger numbers first for lexicographically largest sequence
        for (int num = n; num >= 1; num--) {
            if (used[num]) {
                continue;
            }

            if (num == 1) {
                ans[index] = 1;
                used[1] = true;

                if (solve(index + 1, ans, used, n)) {
                    return true;
                }

                ans[index] = 0;
                used[1] = false;
            } 
            else {
                int secondIndex = index + num;

                if (secondIndex < size && ans[secondIndex] == 0) {
                    ans[index] = num;
                    ans[secondIndex] = num;
                    used[num] = true;

                    if (solve(index + 1, ans, used, n)) {
                        return true;
                    }

                    ans[index] = 0;
                    ans[secondIndex] = 0;
                    used[num] = false;
                }
            }
        }

        return false;
    }

    vector<int> constructDistancedSequence(int n) {
        vector<int> ans(2 * n - 1, 0);
        vector<bool> used(n + 1, false);

        solve(0, ans, used, n);

        return ans;
    }
};