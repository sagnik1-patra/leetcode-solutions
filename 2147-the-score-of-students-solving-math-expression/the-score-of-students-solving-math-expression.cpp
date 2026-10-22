
class Solution {
public:
    vector<int> nums;
    vector<char> ops;
    vector<vector<set<int>>> dp;
    vector<vector<bool>> visited;

    set<int> solve(int l, int r) {
        if (l == r) {
            return {nums[l]};
        }

        if (visited[l][r]) {
            return dp[l][r];
        }

        visited[l][r] = true;

        for (int k = l; k < r; k++) {
            set<int> left = solve(l, k);
            set<int> right = solve(k + 1, r);

            for (int a : left) {
                for (int b : right) {
                    int val;

                    if (ops[k] == '+') {
                        val = a + b;
                    } else {
                        val = a * b;
                    }

                    if (val <= 1000) {
                        dp[l][r].insert(val);
                    }
                }
            }
        }

        return dp[l][r];
    }

    int scoreOfStudents(string s, vector<int>& answers) {
        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                nums.push_back(s[i] - '0');
            } else {
                ops.push_back(s[i]);
            }
        }

        // Calculate correct answer using precedence
        int correct = 0;
        int current = nums[0];

        for (int i = 0; i < ops.size(); i++) {
            if (ops[i] == '*') {
                current *= nums[i + 1];
            } else {
                correct += current;
                current = nums[i + 1];
            }
        }

        correct += current;

        int m = nums.size();

        dp.resize(m, vector<set<int>>(m));
        visited.resize(m, vector<bool>(m, false));

        set<int> possible = solve(0, m - 1);

        int score = 0;

        for (int ans : answers) {
            if (ans == correct) {
                score += 5;
            } else if (possible.count(ans)) {
                score += 2;
            }
        }

        return score;
    }
};
