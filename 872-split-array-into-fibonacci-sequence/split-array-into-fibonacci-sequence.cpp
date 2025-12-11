class Solution {
public:
    vector<int> result;

    bool backtrack(const string &s, int idx) {
        int n = s.size();
        if (idx == n) {
            return result.size() >= 3;
        }

        long long num = 0;
        for (int i = idx; i < n; i++) {
            // Leading zero rule
            if (i > idx && s[idx] == '0') break;

            num = num * 10 + (s[i] - '0');
            if (num > INT_MAX) break;

            int size = result.size();

            // if we have at least 2 numbers, check Fibonacci condition
            if (size >= 2) {
                long long sum = (long long)result[size - 2] + result[size - 1];
                if (num < sum) continue;
                if (num > sum) break;  // Pruning
            }

            result.push_back((int)num);

            if (backtrack(s, i + 1)) return true;

            result.pop_back();  // backtrack
        }

        return false;
    }

    vector<int> splitIntoFibonacci(string num) {
        result.clear();
        backtrack(num, 0);
        return result;
    }
};
