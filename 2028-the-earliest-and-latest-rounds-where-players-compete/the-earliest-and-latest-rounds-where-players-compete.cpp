
class Solution {
public:
    int earliest[29][29][29] = {};
    int latest[29][29][29] = {};

    pair<int, int> solve(int n, int a, int b) {
        if (a + b == n + 1) {
            return {1, 1};
        }

        if (a > b) {
            swap(a, b);
        }

        if (a + b > n + 1) {
            int x = n + 1 - b;
            int y = n + 1 - a;
            a = x;
            b = y;
        }

        if (earliest[n][a][b] != 0) {
            return {earliest[n][a][b],
                    latest[n][a][b]};
        }

        int minRound = INT_MAX;
        int maxRound = 0;
        int nextN = (n + 1) / 2;

        // Enumerate all possible winners
        function<void(int, int, int)> dfs =
            [&](int pos, int beforeA, int beforeB) {

            if (pos > n / 2) {
                if (n % 2 == 1) {
                    int mid = (n + 1) / 2;

                    if (mid < a) beforeA++;
                    if (mid < b) beforeB++;
                }

                int nextA = beforeA + 1;
                int nextB = beforeB + 1;

                auto result = solve(nextN, nextA, nextB);

                minRound = min(minRound, result.first + 1);
                maxRound = max(maxRound, result.second + 1);

                return;
            }

            int left = pos;
            int right = n + 1 - pos;

            if (left == a || right == a) {
                int winner = a;

                dfs(pos + 1,
                    beforeA + (winner < a),
                    beforeB + (winner < b));
            }
            else if (left == b || right == b) {
                int winner = b;

                dfs(pos + 1,
                    beforeA + (winner < a),
                    beforeB + (winner < b));
            }
            else {
                dfs(pos + 1,
                    beforeA + (left < a),
                    beforeB + (left < b));

                dfs(pos + 1,
                    beforeA + (right < a),
                    beforeB + (right < b));
            }
        };

        dfs(1, 0, 0);

        earliest[n][a][b] = minRound;
        latest[n][a][b] = maxRound;

        return {minRound, maxRound};
    }

    vector<int> earliestAndLatest(int n,
                                  int firstPlayer,
                                  int secondPlayer) {
        auto ans = solve(n, firstPlayer, secondPlayer);

        return {ans.first, ans.second};
    }
};
