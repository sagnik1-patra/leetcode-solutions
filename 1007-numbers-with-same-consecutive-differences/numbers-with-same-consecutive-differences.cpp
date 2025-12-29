class Solution {
public:
    vector<int> result;

    void dfs(int num, int length, int n, int k) {
        // Base case: required length reached
        if (length == n) {
            result.push_back(num);
            return;
        }

        int lastDigit = num % 10;

        // Try adding lastDigit + k
        if (lastDigit + k <= 9) {
            dfs(num * 10 + (lastDigit + k), length + 1, n, k);
        }

        // Try adding lastDigit - k (avoid duplicate when k == 0)
        if (k != 0 && lastDigit - k >= 0) {
            dfs(num * 10 + (lastDigit - k), length + 1, n, k);
        }
    }

    vector<int> numsSameConsecDiff(int n, int k) {
        result.clear();

        // Numbers cannot start with 0
        for (int i = 1; i <= 9; i++) {
            dfs(i, 1, n, k);
        }

        return result;
    }
};
